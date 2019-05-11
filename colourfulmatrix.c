
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define assert(ignore) ((void)0)
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[37;41m"
#define KGRN  "\x1B[37;42m"
#define KYEL  "\x1B[37;43m"
#define KBLU  "\x1B[37;44m"
#define KMAG  "\x1B[37;45m"
#define KCYN  "\x1B[37;46m"
#define KWHT  "\x1B[30;47m"

typedef struct {
  int rows;
  int cols;
  double * data;
} matrix;

void print_menu (void);
matrix * newMatrix(int rows, int cols);
int printMatrix(matrix * mtx);
int deleteMatrix(matrix * mtx);

matrix* new_matrix;

int main(){
  printf(KNRM);

  int chosen_option, columnss, rowss;
  char chosen_option_char[10];
  
while(1){
  print_menu();
  scanf("%s", chosen_option_char);
  chosen_option = atoi(&chosen_option_char[0]);
  if(chosen_option == 1 ||
     chosen_option == 2 ||
     chosen_option == 3 ||
     chosen_option == 4 ||
     chosen_option == 5 ){
    if(chosen_option == 1){
      printf("Enter the number of COLUMNS in your matrix>\n");
      scanf("%i", &columnss);
      printf("Enter the number of ROWS in your matrix>\n");
      scanf("%i", &rowss);
      new_matrix = newMatrix(rowss, columnss);
    }
    else if(chosen_option == 2){
      printMatrix(new_matrix);
    }
    else if(chosen_option == 5){
         deleteMatrix(new_matrix);
        return 0;
      }
    else{
      printf("Invalid choice\n");
      }
    } else printf("Invalid choice\n");
  } return 0;
}


void print_menu (void)
{
  printf("\n"
           "1. add a matrix\n"
           "2. print a matrix\n"
           "3. save matrix\n"
           "4. load matrix\n"
           "5. exit the program\n"
           "Enter choice (number between 1-5)>\n");
}


/* Creates a ``rows by cols'' matrix with all values 0.  
 * Returns NULL if rows <= 0 or cols <= 0 and otherwise a
 * pointer to the new matrix.
 */
matrix * newMatrix(int rows, int cols) {
  if (rows <= 0 || cols <= 0) return NULL;
  
  /* allocate a matrix structure */
  matrix * m = (matrix *) malloc(sizeof(matrix));
  
  /* set dimensions */
  m->rows = rows;
  m->cols = cols;
  
  /* allocate a double array of length rows * cols */
  m->data = (double *) malloc(rows*cols*sizeof(double));
  /* set all data to 0 */
  int i;
  for (i = 0; i < rows*cols; i++)
    m->data[i] = 0.0;
  
  return m;
}

/* Deletes a matrix.  Returns 0 if successful and -1 if mtx 
 * is NULL.
 */
int deleteMatrix(matrix * mtx) {
  if (!mtx) return -1;
  /* free mtx's data */
  assert (mtx->data);
  free(mtx->data);
  /* free mtx itself */
  free(mtx);
  return 0;
}

#define ELEM(mtx, row, col) \
mtx->data[(col-1) * mtx->rows + (row-1)]

/* Copies a matrix.  Returns NULL if mtx is NULL.
 */
matrix * copyMatrix(matrix * mtx) {
  if (!mtx) return NULL;
  
  /* create a new matrix to hold the copy */
  matrix * cp = newMatrix(mtx->rows, mtx->cols);
  
  /* copy mtx's data to cp's data */
  memcpy(cp->data, mtx->data, 
         mtx->rows * mtx->cols * sizeof(double));
  
  return cp;
}

/* Sets the (row, col) element of mtx to val.  Returns 0 if
 * successful, -1 if mtx is NULL, and -2 if row or col are
 * outside of the dimensions of mtx.
 */
int setElement(matrix * mtx, int row, int col, double val) 
{
  if (!mtx) return -1;
  assert (mtx->data);
  if (row <= 0 || row > mtx->rows ||
      col <= 0 || col > mtx->cols)
    return -2;
  
  ELEM(mtx, row, col) = val;
  return 0;
}

/* Sets the reference val to the value of the (row, col) 
 * element of mtx.  Returns 0 if successful, -1 if either 
 * mtx or val is NULL, and -2 if row or col are outside of 
 * the dimensions of mtx.
 */
int getElement(matrix * mtx, int row, int col, 
               double * val) {
  if (!mtx || !val) return -1;
  assert (mtx->data);
  if (row <= 0 || row > mtx->rows ||
      col <= 0 || col > mtx->cols)
    return -2;
  
  *val = ELEM(mtx, row, col);
  return 0;
}

/* Sets the reference n to the number of rows of mtx.
 * Returns 0 if successful and -1 if mtx or n is NULL.
 */
int nRows(matrix * mtx, int * n) {
  if (!mtx || !n) return -1;
  *n = mtx->rows;
  return 0;
}

/* Sets the reference n to the number of columns of mtx.
 * Returns 0 if successful and -1 if mtx is NULL.
 */
int nCols(matrix * mtx, int * n) {
  if (!mtx || !n) return -1;
  *n = mtx->rows;
  return 0;
}

/* Prints the matrix to stdout.  Returns 0 if successful 
 * and -1 if mtx is NULL.
 */
int printMatrix(matrix * mtx) {
  if (!mtx) return -1;
  
  int counter = 0;
  int row, col;
  for (row = 1; row <= mtx->rows; row++) {
    for (col = 1; col <= mtx->cols; col++) {
      /* Print the floating-point element with
      //  - either a - if negative or a space if positive
      //  - at least 3 spaces before the .
      //  - precision to the hundredths place */
      
      counter++;
      if(counter == 1 || counter % 8 == 1)
        printf(KRED);
      else if(counter == 2 || counter % 8 == 2) 
        printf(KGRN);
        
      else if(counter == 3 || counter % 8 == 3)
        printf(KYEL);
      else if(counter == 4 || counter % 8 == 4)
      printf(KBLU);
      else if(counter == 5 || counter % 8 == 5)
      printf(KMAG);
      else if(counter == 6 || counter % 8 == 6)
      printf(KCYN);
      else if(counter == 7 || counter % 8 == 7)
      printf(KWHT);
      else if(counter == 8 || counter % 8 == 0)
      printf(KNRM);
      printf("% 6.2f ", ELEM(mtx, row, col));
    }
    /* separate rows by newlines */
    printf("\n");
  }
  printf(KNRM);
  return 0;
}

 

/* Writes the transpose of matrix in into matrix out.  
 * Returns 0 if successful, -1 if either in or out is NULL,
 * and -2 if the dimensions of in and out are incompatible.
 */
int transpose(matrix * in, matrix * out) {
  if (!in || !out) return -1;
  if (in->rows != out->cols || in->cols != out->rows)
    return -2;
  
  int row, col;
  for (row = 1; row <= in->rows; row++)
    for (col = 1; col <= in->cols; col++)
      ELEM(out, col, row) = ELEM(in, row, col);
  return 0;
}

/* Writes the sum of matrices mtx1 and mtx2 into matrix 
 * sum. Returns 0 if successful, -1 if any of the matrices 
 * are NULL, and -2 if the dimensions of the matrices are
 * incompatible.
 */
int sum(matrix * mtx1, matrix * mtx2, matrix * sum) {
  if (!mtx1 || !mtx2 || !sum) return -1;
  if (mtx1->rows != mtx2->rows ||
      mtx1->rows != sum->rows ||
      mtx1->cols != mtx2->cols ||
      mtx1->cols != sum->cols)
    return -2;
  
  int row, col;
  for (col = 1; col <= mtx1->cols; col++)
    for (row = 1; row <= mtx1->rows; row++)
      ELEM(sum, row, col) = 
        ELEM(mtx1, row, col) + ELEM(mtx2, row, col);
  return 0;
}

/* Writes the product of matrices mtx1 and mtx2 into matrix
 * prod.  Returns 0 if successful, -1 if any of the 
 * matrices are NULL, and -2 if the dimensions of the 
 * matrices are incompatible.
 */
int product(matrix * mtx1, matrix * mtx2, matrix * prod) {
  if (!mtx1 || !mtx2 || !prod) return -1;
  if (mtx1->cols != mtx2->rows ||
      mtx1->rows != prod->rows ||
      mtx2->cols != prod->cols)
    return -2;
  
  int row, col, k;
  for (col = 1; col <= mtx2->cols; col++)
    for (row = 1; row <= mtx1->rows; row++) {
      double val = 0.0;
      for (k = 1; k <= mtx1->cols; k++)
        val += ELEM(mtx1, row, k) * ELEM(mtx2, k, col);
      ELEM(prod, row, col) = val;
    }
    return 0;
}

/* Writes the dot product of vectors v1 and v2 into 
 * reference prod.  Returns 0 if successful, -1 if any of
 * v1, v2, or prod are NULL, -2 if either matrix is not a 
 * vector, and -3 if the vectors are of incompatible 
 * dimensions.
 */
int dotProduct(matrix * v1, matrix * v2, double * prod) {
  if (!v1 || !v2 || !prod) return -1;
  if (v1->cols != 1 || v2->cols != 1) return -2;
  if (v1->rows != v2->rows) return -3;
  
  *prod = 0;
  int i;
  for (i = 1; i <= v1->rows; i++)
    *prod += ELEM(v1, i, 1) * ELEM(v2, i, 1);
  return 0;
}

int identity(matrix * m) {
  if (!m || m->rows != m->cols) return -1;
  int row, col;
  for (col = 1; col <= m->cols; col++)
    for (row = 1; row <= m->rows; row++)
      if (row == col) 
        ELEM(m, row, col) = 1.0;
      else 
        ELEM(m, row, col) = 0.0;
      return 0;
}

int isSquare(matrix * mtx) {
  return mtx && mtx->rows == mtx->cols;
}

int isDiagonal(matrix * mtx) {
  if (!isSquare(mtx)) return 0;
  int row, col;
  for (col = 1; col <= mtx->cols; col++)
    for (row = 1; row <= mtx->rows; row++)
      /* if the element is not on the diagonal and not 0 */
      if (row != col && ELEM(mtx, row, col) != 0.0)
        /* then the matrix is not diagonal */
        return 0;
      return 1;
}

int isUpperTriangular(matrix * mtx) {
  if (!isSquare(mtx)) return 0;
  int row, col;
  /* looks at positions below the diagonal */
  for (col = 1; col <= mtx->cols; col++)
    for (row = col+1; row <= mtx->rows; row++) 
      if (ELEM(mtx, row, col) != 0.0)
        return 0;
      return 1;
}

int diagonal(matrix * v, matrix * mtx) {
  if (!v || !mtx ||
      v->cols > 1 || v->rows != mtx->rows ||
      mtx->cols != mtx->rows)
    return -1;
  int row, col;
  for (col = 1; col <= mtx->cols; col++)
    for (row = 1; row <= mtx->rows; row++)
      if (row == col) 
        ELEM(mtx, row, col) = ELEM(v, col, 1);
      else
        ELEM(mtx, row, col) = 0.0;
      return 0;
}

/*
int main() {
  matrix * A, * Ac, * B, * c, * d, * M, * ct, * mdp;
  double dp;
  
  A = newMatrix(3, 3);
  setElement(A, 1, 1, 1.0);
  setElement(A, 1, 2, .25);
  setElement(A, 1, 3, -.1);
  setElement(A, 2, 2, .4);
  setElement(A, 2, 3, .3);
  setElement(A, 3, 2, .1);
  setElement(A, 3, 3, -.3);
  printf("Matrix A:\n");
  printMatrix(A);
  
  Ac = copyMatrix(A);
  printf("\nCopy of A:\n");
  printMatrix(Ac);
  
  B = newMatrix(3, 3);
  setElement(B, 1, 1, .5);
  setElement(B, 2, 2, 2.0);
  setElement(B, 3, 3, 1.0);
  printf("\nMatrix B:\n");
  printMatrix(B);
  
  c = newMatrix(3, 1);
  setElement(c, 1, 1, 1.0);
  setElement(c, 3, 1, 1.0);
  printf("\nVector c:\n");
  printMatrix(c);
  
  d = newMatrix(3, 1);
  setElement(d, 2, 1, 1.0);
  setElement(d, 3, 1, 1.0);
  printf("\nVector d:\n");
  printMatrix(d);
  
  M = newMatrix(3, 3);
  transpose(A, M);
  printf("\nA':\n");
  printMatrix(M);
  
  ct = newMatrix(1, 3);
  transpose(c, ct);
  printf("\nc':\n");
  printMatrix(ct);
  
  sum(A, B, M);
  printf("\nA + B:\n");
  printMatrix(M);
  
  product(A, B, M);
  printf("\nA * B:\n");
  printMatrix(M);
  
  mdp = newMatrix(1, 1);
  product(ct, d, mdp);
  getElement(mdp, 1, 1, &dp);
  printf("\nDot product (1): %.2f\n", dp);
  
  dotProduct(c, d, &dp);
  printf("\nDot product (2): %.2f\n", dp);
  
  product(A, c, d);
  printf("\nA * c:\n");
  printMatrix(d);
  
  printf("\nisUpperTriangular(A): %d"
           "\nisUpperTriangular(B): %d"
           "\nisDiagonal(A): %d"
           "\nisDiagonal(B): %d\n",
           isUpperTriangular(A),
           isUpperTriangular(B),
           isDiagonal(A),
           isDiagonal(B));
  
  identity(A);
  printf("\nIdentity:\n");
  printMatrix(A);
  
  diagonal(c, A);
  printf("\nDiagonal from c:\n");
  printMatrix(A);
  
  deleteMatrix(A);
  deleteMatrix(Ac);
  deleteMatrix(B);
  deleteMatrix(c);
  deleteMatrix(d);
  deleteMatrix(M);
  deleteMatrix(ct);
  deleteMatrix(mdp);
  
  return 0;
}
 
 */
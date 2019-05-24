/*
 *          Matrix Manipulation Implementation File for:
 *          Programming Fundamentals with C Assessment Task 3 - Group Assessment
 *
 *          ColourMatrix.c
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ColourMatrix.h"

#define assert(ignore) ((void)0)

/* List of font and background colour combinations used by printMatrix */
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[37;41m"
#define KGRN  "\x1B[37;42m"
#define KYEL  "\x1B[37;43m"
#define KBLU  "\x1B[37;44m"
#define KMAG  "\x1B[37;45m"
#define KCYN  "\x1B[37;46m"
#define KWHT  "\x1B[30;47m"

/* Name of the db file */
#define DB_NAME "db.txt"

/* Frees any allocated memory for the supplied matrix */
int deleteMatrix(float * mtx) {
  if (!mtx) return -1;
  /* free mtx's data */
  assert (mtx);
  free(mtx);
  mtx = NULL;
  return 0;
}


/* Uses a nested loop to cycle through each row and column, printing each value as it goes
 *
 * Before landing on the value it is about to print, this function changes the background colour and font colour (there are 8 colour combinations
 * that it cycles through)
 */
int printMatrix(matrix_t* our_matrix, int index) {
  int max_col = our_matrix[index].columns;
  float *data = our_matrix[index].data;
  int counter = 0;
  int row = 0, col = 0;
  for (col = 1; col <= our_matrix[index].columns; col++) {
    for (row = 1; row <= our_matrix[index].rows; row++) {
      counter++;
      if(counter == 1 || counter % 8 == 1)                              /* This bit sets the colour of the printer */
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

    /*  printf(" %2.f ", *our_matrix[index].data+(col-1)*(row-1));  */      /* This line prints the corresponding row+col of the nested loop */
      printf(" %2.f ", data[(col-1) + (row-1) * max_col]);
    }
    /* separate rows by newlines */
    printf(KNRM); 
    printf("\n");
  }
  printf(KNRM);                                                         /* Set colour back to normal */
    return 0;
}

/* Creates a matrix by returning a 2d array of the dimensions matrix[rows1][cols1]
 *
 * This function asks for user input for number of rows and columns, then returns a 2d array of matching dimensions.
 *
 * rows1 and cols1 are int* values that get updated and are used by other functions such as printMatrix
 */

/*

float* create_matrix(int * cols1, int* rows1){
  int rows, cols;

  printf("Enter the number of rows>\n");
  scanf("%d", &rows);

  printf("Enter the number of cols>\n");
  scanf("%d", &cols);

  float * our_matrix = (float *) malloc(rows * cols * sizeof(float));

  *cols1 = cols;
  *rows1 = rows;

  return our_matrix;

}
 
*/ 

int create_matrix(matrix_t* matrixP, int matrixLocation){

  char tempName[50];
  int rows, cols;
  
  
  printf("Enter a name for your matrix>\n");
  scanf("%s", tempName);

  printf("Enter the number of rows>\n");
  scanf("%d", &rows);

  printf("Enter the number of cols>\n");
  scanf("%d", &cols);
  
  float * our_matrix = (float *) malloc(rows * cols * sizeof(float));  

  strcpy(matrixP[matrixLocation].matrixName, tempName);
  matrixP[matrixLocation].rows = rows;
  matrixP[matrixLocation].columns = cols;
  matrixP[matrixLocation].data = our_matrix;

  return 0;

}


int setValues(matrix_t* our_matrix, int matrix_index) {
  int max_col = our_matrix[matrix_index].columns;
  float *data = our_matrix[matrix_index].data;
  int row = 0, col = 0;
  for (col = 1; col <= our_matrix[matrix_index].columns; col++) {
    for (row = 1; row <= our_matrix[matrix_index].rows; row++) {
      
      printf("Enter the value for column number %d of row number %d>\n", col, row);
      scanf("%f", data + (col-1) + (row-1) * max_col);
    }
    /* separate rows by newlines */
  }
  our_matrix[matrix_index].data = data;
    return 0;
}


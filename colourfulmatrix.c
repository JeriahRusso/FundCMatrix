
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



float* create_matrix(int * cols1, int* rows1);
int deleteMatrix(float * mtx); 



void print_menu (void);
matrix * newMatrix(int rows, int cols);
int printMatrix(float * our_matrix, int* rows1, int* cols1);


float* new_matrix;

int main(){
  printf(KNRM);

  int chosen_option;
  char chosen_option_char[10];
  int rows_example = 0; 
  int cols_example = 0;
  int* rows1 = &rows_example; 
  int* cols1 = &cols_example;
  
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
      new_matrix = create_matrix(rows1, cols1);
    }
    else if(chosen_option == 2){
      printMatrix(new_matrix, rows1, cols1);
    }
    else if(chosen_option == 5){
         deleteMatrix(new_matrix);
        return 0;
      }
    else{
      printf("Invalid choice\n");
      }
   }
}
return 0;
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



int deleteMatrix(float * mtx) {
  if (!mtx) return -1;
  /* free mtx's data */
  assert (mtx);
  free(mtx);
  mtx = NULL;
  return 0;
}

#define ELEM(our_matrix, row, col) float our_matrix[row][col]






int printMatrix(float * our_matrix, int * rows1, int * cols1) {
  if (!our_matrix) return -1;
  
  int counter = 0;
  int row, col;
  for (row = 1; row <= *rows1; row++) {
    for (col = 1; col <= *cols1; col++) {
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
      printf(" %2.f ", *our_matrix+(row-1)+(col-1));
    }
    /* separate rows by newlines */
    printf("\n");
  }
  printf(KNRM);
  return 0;
}

 

/*

float mean(float *ptr, int length){
  float sum, mean;
  int i;
  
  for(i = 0; i < length; i++){
    sum = sum + ptr[i];
  }
  
  mean = sum / (i + 1);
  
  printf("The mean is %.2lf", mean);
  
  return mean;  
}

 */



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
 
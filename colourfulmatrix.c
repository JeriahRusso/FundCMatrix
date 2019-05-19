
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "accounts.h"

/* The macros define the colour palette variables for background and font colour */

#define assert(ignore) ((void)0)
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[37;41m"
#define KGRN  "\x1B[37;42m"
#define KYEL  "\x1B[37;43m"
#define KBLU  "\x1B[37;44m"
#define KMAG  "\x1B[37;45m"
#define KCYN  "\x1B[37;46m" 
#define KWHT  "\x1B[30;47m"
#define DB_NAME "db.txt"




user_t user[100];

int number_of_users = 0;

float* create_matrix(int * cols1, int* rows1);                    /* Creates a matrix */
int deleteMatrix(float * mtx);                                    /* Frees memory     */
void print_menu (void);                                           /* Print menu       */
int printMatrix(float * our_matrix, int* rows1, int* cols1);      /* Print matrix     */
  
/* MAIN -----------------------------------------------------------------------------------------------------------------------------|
 *                                                                                                                                   |    
 */
  

int main(){
  printf(KNRM);                                                   /* Set colour palette to normal */
  float* new_matrix;                                              /* Initialise a matrix object   */

  char chosen_option_char[10], chosen_user_option_char[10];       /* Read string, store in here   */
  int chosen_option, chosen_user_option;                          /* Convert string to int        */
  int rows_example = 0;                                           /* Main func rows variable      */
  int cols_example = 0;                                           /* Main func cols variable      */
  int* rows1 = &rows_example;                                     /* Pointer to rows              */
  int* cols1 = &cols_example;                                     /* Pointer to cols              */
  user_t user[100];
  int logged_in = 0;               
  
  number_of_users = load_users_from_file(user);

  
while(logged_in == 0){   
  
  user_menu();
  
  scanf("%s", chosen_user_option_char);
  chosen_user_option = atoi(&chosen_user_option_char[0]);
  
  if(chosen_user_option == 1 ||
     chosen_user_option == 2){
    if(chosen_user_option == 1){
      create_user(user, number_of_users);
      save_users_to_db(user, number_of_users);
      number_of_users++;
    }
    else if(chosen_user_option == 2){
      user_login(user, number_of_users);
      logged_in = 1;
    }
  }
}

printf("Login Successful\n");
  
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
  
/* FUNCTIONS ---------------------------------------------------------------------------------------------------------------------------|
 *                                                                                                                                      |
 */

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

int printMatrix(float * our_matrix, int * rows1, int * cols1) {
  int counter = 0;
  int row = 0, col = 0;
  for (col = 1; col <= *cols1; col++) {
    for (row = 1; row <= *rows1; row++) {
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
      
          printf(" %2.f ", *our_matrix+(col-1)+(row-1));                /* This line prints the corresponding row+col of the nested loop */
    }
    /* separate rows by newlines */
    printf("\n");
  }
  printf(KNRM);                                                         /* Set colour back to normal */
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






#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "accounts.h"
#include "ColourMatrix.h"



user_t user[100];
matrix_t matrix[100];
int number_of_users = 0;
void print_menu (void);                                           /* Print menu       */

/* MAIN -----------------------------------------------------------------------------------------------------------------------------|
 *                                                                                                                                   |
 */

/* TODO:  When creating a new matrix allocate the memory here */

int main(){
  printf(KNRM);                                                   /* Set colour palette to normal */
                                                                  /* Initialise a matrix object   */

  char chosen_option_char[10], chosen_user_option_char[10];       /* Read string, store in here   */
  int chosen_option, chosen_user_option;                          /* Convert string to int        */
  user_t user[100];
  int logged_in = 0;
  int number_of_matrices = 0;
  int matrix_index = 0;

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
      create_matrix(matrix, number_of_matrices);
      number_of_matrices++;
    }
    else if(chosen_option == 2){
      printf("Which matrix would you like to print? Enter a number>\n");
      scanf("%d", &matrix_index);
      printMatrix(matrix, matrix_index);
    }
    else if(chosen_option == 5){
      free(matrix);
        /* deleteMatrix(new_matrix); */
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

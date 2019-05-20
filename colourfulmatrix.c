
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "accounts.h"
#include "ColourMatrix.h"



user_t user[100];
int number_of_users = 0;
void print_menu (void);                                           /* Print menu       */

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






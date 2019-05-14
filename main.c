#include <stdio.h>

struct matrix{
    char names[][];
    float data[][];
};
typedef struct matrix matix_t;
/*The above structure contains the header section and the 
  actual matrix itself. This is made for users who are 
  trying to process data tables using matix operations.
  Suggested by Davide Lorino****************************/

int login();
/*This is a function for user login. We are aiming for 
  the co-existence of multiple users within this program,
  each has their own data storage.
  Suggested by Davide Lorino****************************/
void printMenu();
/*Just the menu, nothing special.
  Suggested by Jeriah Russo******************************/
float[][] generateMatrix();
/*This function allows the user to create matrices by 
  first taking the values for number of columns and rows,
  then take in one input at a time until the matrix is 
  complete.
  Suggested by Jeriah Russo*******************************/
float[][] readMatrixFromFile(char* fileLocation);
/*This is another thing we would like to try, and it is to
  read matrices from files in .csv format. We might try to
  include more file formats in future.
  Suggested by Jeriah Russo*******************************/
float dotProduct(float[][] mat1, float[][] mat2);
/*Dot product operation. Just that.
  Suggested by Jeriah Russo*****************************/

int main(void){

    return 1;
}

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

int deleteMatrix(float * mtx) {
  if (!mtx) return -1;
  /* free mtx's data */
  assert (mtx);
  free(mtx);
  mtx = NULL;
  return 0;
}

int printMatrix(matrix_t* our_matrix, int number_of_matrices) {
  int counter = 0;
  int index = 0;
  int row = 0, col = 0, i = 0;

  system("clear");
  for(i = 0; i < number_of_matrices; i++){
    printf("Matrix %i\t %i Rows\t %i Columns - Name: %s\n", i+1,
        our_matrix[i].rows, our_matrix[i].columns, our_matrix[i].matrixName);
  }
  printf("\n");

  printf("Which matrix would you like to print?"
         " Enter the matrix number from the list above\n");

  scanf("%d", &index);

  while(index < 1 || index > number_of_matrices){
    printf("Enter a number from the list of available matrices - "
        "number must be greater than zero and less than or equal to the "
        "number of available matrices:\n");
    scanf("%d", &index);
  }

  index -= 1;

  int max_col = our_matrix[index].columns;
  float *data = our_matrix[index].data;

  for (row = 0; row < our_matrix[index].rows; row++) {
    for (col = 0; col < our_matrix[index].columns; col++) {
      counter++;
       /* This bit sets the colour of the printer */
      if(counter % 8 == 1)
        printf(KRED);
      else if(counter % 8 == 2)
        printf(KGRN);
      else if(counter % 8 == 3)
        printf(KYEL);
      else if(counter % 8 == 4)
        printf(KBLU);
      else if(counter % 8 == 5)
        printf(KMAG);
      else if(counter % 8 == 6)
        printf(KCYN);
      else if(counter % 8 == 7)
        printf(KWHT);
      else if(counter % 8 == 0)
        printf(KNRM);

    /*  printf(" %2.f ", *our_matrix[index].data+(col-1)*(row-1));  */
    /* This line prints the corresponding row+col of the nested loop */
      printf(" %2.f ", data[(col) + (row) * max_col]);
    }
    /* separate rows by newlines */
    printf(KNRM);
    printf("\n");
  }
  printf(KNRM);                                 /* Set colour back to normal */
  printf("Press ENTER to return to menu.");
  getchar();
    return 0;
}

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

  int row, col;
  for (row = 0; row < rows; row++) {
    for (col = 0; col < cols; col++) {
      our_matrix[(col) + (row) * cols] = 0;
    }
  }

  strcpy(matrixP[matrixLocation].matrixName, tempName);
  matrixP[matrixLocation].rows = rows;
  matrixP[matrixLocation].columns = cols;
  matrixP[matrixLocation].data = our_matrix;

  return 0;

}


int setValues(matrix_t* our_matrix, int number_of_matrices) {
  int i, matrix_index;
  for(i = 0; i < number_of_matrices; i++){
    printf("Matrix %i\t %i Rows\t %i Columns - Name: %s\n", i+1,
        our_matrix[i].rows, our_matrix[i].columns, our_matrix[i].matrixName);
  }

  printf("\nWhich matrix would you like to set the values for?\n");
  printf("Select a matrix number from the list above>\n");

  scanf("%d", &matrix_index);

  while(matrix_index < 1 || matrix_index > number_of_matrices){
    printf("Enter a number from the list of available matrices -"
        " number must be greater than zero and less than or equal to the"
        " number of available matrices:\n");
    scanf("%d", &matrix_index);
  }

  int max;
  matrix_index -= 1;
  max = our_matrix[matrix_index].columns;


  float *data = our_matrix[matrix_index].data;
  int row = 0, col = 0;
  for (row = 0; row < our_matrix[matrix_index].rows; row++) {
    for (col = 0; col < our_matrix[matrix_index].columns; col++) {

      printf("Enter the value for column number %d of row number %d>\n",
                col+1, row+1);
        scanf("%f", &data[(col) + (row) * (max)]);

    /* separate rows by newlines */
  }
  }
  our_matrix[matrix_index].data = data;
    return 0;
}

int addMatrix(matrix_t* our_matrix, int matrix_index1, int matrix_index2,
                int number_of_matrices){
  if(our_matrix[matrix_index1].columns == our_matrix[matrix_index2].columns){
    if(our_matrix[matrix_index1].rows == our_matrix[matrix_index2].rows){
      our_matrix[number_of_matrices].rows = our_matrix[matrix_index2].rows;
      our_matrix[number_of_matrices].columns =
        our_matrix[matrix_index2].columns;
      int max_col = our_matrix[matrix_index1].columns;
      free(our_matrix[number_of_matrices].data);
      our_matrix[number_of_matrices].data =
            (float *) malloc(our_matrix[matrix_index1].rows
            * our_matrix[matrix_index1].columns * sizeof(float));
      float *data1 = our_matrix[matrix_index1].data;
      float *data2 = our_matrix[matrix_index2].data;
      char temp_name[50];
      printf("Enter the name you would like to give to your"
                " resulting matrix>\n");
      scanf("%s", temp_name);
      int col, row;
      for(row = 0; row < our_matrix[matrix_index2].rows; row++){
        for(col = 0; col < our_matrix[matrix_index2].columns; col++){
          our_matrix[number_of_matrices].data[(row) + (col) * max_col] =
          (data1[(row) + (col) * (max_col)]) +
            (data2[(row) + (col) * (max_col)]);
        }
      }

    strcpy(our_matrix[number_of_matrices].matrixName, temp_name);

    printf("Success!\n");
    printf("Matrix %i\t %i Rows\t %i Columns\t Name: %s\n",
        number_of_matrices + 1, our_matrix[number_of_matrices].rows,
        our_matrix[number_of_matrices].columns,
        our_matrix[number_of_matrices].matrixName);

    row = 0, col = 0;
    int counter = 0;
    for (row = 0; row < our_matrix[number_of_matrices].rows; row++) {
      for (col = 0; col < our_matrix[number_of_matrices].columns; col++) {
        counter++;
        /* This bit sets the colour of the printer */
        if(counter % 8 == 1)
          printf(KRED);
        else if(counter % 8 == 2)
          printf(KGRN);
        else if(counter % 8 == 3)
          printf(KYEL);
        else if (counter % 8 == 4)
          printf(KBLU);
        else if(counter % 8 == 5)
          printf(KMAG);
        else if(counter % 8 == 6)
          printf(KCYN);
        else if(counter % 8 == 7)
          printf(KWHT);
        else if(counter % 8 == 0)
          printf(KNRM);

        /*  printf(" %2.f ", *our_matrix[index].data+(col-1)*(row-1));  */
        /* This line prints the corresponding row+col of the nested loop */
        printf(" %2.f ",
            our_matrix[number_of_matrices].data[(row) + (col) * max_col]);
      }
      /* separate rows by newlines */
      printf(KNRM);
      printf("\n");
    }

      return 1;
    }
  }
  printf("Matrices are not of equal size - addition is not possible.\n");
  return 0;
}

int subtractMatrix(matrix_t* our_matrix, int matrix_index1, int matrix_index2,
                        int number_of_matrices){
  char temp_name[50];
  printf("Enter the name you would like to give to your resulting matrix>\n");
  scanf("%s", temp_name);
  if(our_matrix[matrix_index1].columns == our_matrix[matrix_index2].columns){
    if(our_matrix[matrix_index1].rows == our_matrix[matrix_index2].rows){
      our_matrix[number_of_matrices].rows = our_matrix[matrix_index2].rows;
      our_matrix[number_of_matrices].columns =
        our_matrix[matrix_index2].columns;
      int max_col = our_matrix[matrix_index1].columns;
      free(our_matrix[number_of_matrices].data);
      our_matrix[number_of_matrices].data =
        (float *) malloc(our_matrix[matrix_index1].rows
            * our_matrix[matrix_index1].columns * sizeof(float));
      float *data1 = our_matrix[matrix_index1].data;
      float *data2 = our_matrix[matrix_index2].data;

      int col, row;
      for(col = 0; col < our_matrix[matrix_index2].columns; col++){
        for(row = 0; row < our_matrix[matrix_index2].rows; row++){
          our_matrix[number_of_matrices].data[(col) + (row) * max_col] =
            (data1[(col) + (row) * (max_col)]) -
            (data2[(col) + (row) * (max_col)]);
        }
      }
      strcpy(our_matrix[number_of_matrices].matrixName, temp_name);

      printf("Success!\n");
      printf("Matrix %i\t %i Rows\t %i Columns\t Name: %s\n",
        number_of_matrices + 1, our_matrix[number_of_matrices].rows,
        our_matrix[number_of_matrices].columns,
        our_matrix[number_of_matrices].matrixName);

      row = 0, col = 0;
      int counter = 0;
      for (row = 1; row <= our_matrix[number_of_matrices].rows; row++) {
        for (col = 1; col <= our_matrix[number_of_matrices].columns; col++) {
             counter++;
          /* This bit sets the colour of the printer */
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

          /*  printf(" %2.f ", *our_matrix[index].data+(col-1)*(row-1));  */
          /* This line prints the corresponding row+col of the nested loop */
          printf(" %2.f ",
            our_matrix[number_of_matrices].data[(row-1) + (col-1) * max_col]);
        }
        /* separate rows by newlines */
        printf(KNRM);
        printf("\n");
      }

      return 1;
    }
  }
  printf("Matrices are not of equal size - subtraction is not possible.\n");
  return 0;
}

void showMatrixNames(matrix_t* matrix, int number_of_matrices){
  int i;
  printf("The number of stored matrices is %d\n", number_of_matrices);
  for(i = 0; i < number_of_matrices; i++){
    printf("Matrix %i\t %i Rows\t %i Columns - Name: %s\n", i+1,
        matrix[i].rows, matrix[i].columns, matrix[i].matrixName);
  }
  printf("\n");
}

int dotProductMatrix(matrix_t* our_matrix, int matrix_index1, int matrix_index2,
                        int number_of_matrices){
  char temp_name[50];
  printf("Enter the name you would like to give to your resulting matrix>\n");
  scanf("%s", temp_name);
  if(our_matrix[matrix_index1].columns == our_matrix[matrix_index2].rows){
      free(our_matrix[number_of_matrices].data);
      our_matrix[number_of_matrices].data =
        (float *) malloc(our_matrix[matrix_index1].rows *
                our_matrix[matrix_index2].columns * sizeof(float));
      int i, j, k, mA_Rows, mA_Cols, mB_Rows, mB_Cols;

      mA_Rows = our_matrix[matrix_index1].rows;
      mB_Rows = our_matrix[matrix_index2].rows;
      mA_Cols = our_matrix[matrix_index1].columns;
      mB_Cols = our_matrix[matrix_index2].columns;

      our_matrix[number_of_matrices].rows = our_matrix[matrix_index1].rows;
      our_matrix[number_of_matrices].columns =
            our_matrix[matrix_index2].columns;

      for(i = 0; i < mA_Rows; i++){
        for(j = 0; j < mB_Cols; j++){
          float sum = 0.0;
          for(k = 0; k < mB_Rows; k++)
              sum = sum + our_matrix[matrix_index1].data[i * mA_Cols + k] *
                            our_matrix[matrix_index2].data[k * mB_Cols + j];
          our_matrix[number_of_matrices].data[i *
            our_matrix[number_of_matrices].columns + j] = sum;
        }
      }

      strcpy(our_matrix[number_of_matrices].matrixName, temp_name);

      printf("Success!\n");
      printf("Matrix %i\t %i Rows\t %i Columns\t Name: %s\n",
        number_of_matrices + 1, our_matrix[number_of_matrices].rows,
        our_matrix[number_of_matrices].columns,
        our_matrix[number_of_matrices].matrixName);

  return 1;
  }
  else{
    printf("Matrices do not have required dimensions for multiplication. "
            "Try again.\n");
    return 0;
  }
}

void saveSessionToFile(matrix_t* matrices, int number_of_matrices,
                        char* fileName){
    int i, j, occurrence;
    float data;
    FILE* fp;

    fp = fopen(fileName, "w");
    for(i = 0; i < number_of_matrices; i++){
        occurrence = 0;
        data = matrices[i].data[0];
        fprintf(fp, "%s,", matrices[i].matrixName);
        fprintf(fp, "%d,", matrices[i].rows);
        fprintf(fp, "%d,", matrices[i].columns);
        for(j = 0; j < matrices[i].rows * matrices[i].columns; j++){
            if(matrices[i].data[j] == data){
                occurrence++;
            }else{
                fprintf(fp, "%d,%f,", occurrence, data);
                occurrence = 1;
                data = matrices[i].data[j];
            }
        }
        fprintf(fp, "%d,%f,\n", occurrence, data);
    }
    fclose(fp);
    printf("Session saved as %s.\n", fileName);
}

int loadSessionFromFile(matrix_t* matrix, char* file){
    int stage, i, matrixNum, dataLoc, repeat;
    FILE* fp;
    char inChar;
    char dataHolder[MAX_FILE_NAME];

    i = 0;
    stage = 0;
    matrixNum = 0;
    dataLoc = 0;
    repeat = 0;
    if(!(fp = fopen(file, "r"))){
        printf("File %s does not exist.\n", file);
        return 0;
    }
    cleanString(dataHolder);

    inChar = getc(fp);
    while(inChar != EOF){
        while(inChar != ',' && inChar != '\n' && inChar != EOF){
            dataHolder[i] = inChar;
            i++;
            inChar = getc(fp);
        }
        dataHolder[++i] = '\0';
        if(inChar == ','){
            switch(stage){
                case 0:
                    strcpy(matrix[matrixNum].matrixName, dataHolder);
                    stage++;
                    break;
                case 1:
                    matrix[matrixNum].rows = atoi(dataHolder);
                    stage++;
                    break;
                case 2:
                {
                    matrix[matrixNum].columns = atoi(dataHolder);
                    int row, col, rows, cols;
                    rows = matrix[matrixNum].rows;
                    cols = matrix[matrixNum].columns;
                    float * our_matrix = (float *) malloc(rows * cols
                                            * sizeof(float));

                    for (row = 0; row < rows; row++) {
                        for (col = 0; col < cols; col++) {
                            our_matrix[(col) + (row) * cols] = 0;
                        }
                    }

                    matrix[matrixNum].data = our_matrix;
                    stage++;
                    break;
                }
                case 3:
                {
                    repeat = atoi(dataHolder);
                    stage++;
                    break;
                }
                case 4:
                {
                    int rep;
                    for(rep = 0; rep < repeat; rep++){
                        matrix[matrixNum].data[dataLoc] = atof(dataHolder);
                        dataLoc++;
                    }
                    stage--;
                    break;
                }
            }
            cleanString(dataHolder);
            i = 0;
        }else{
            matrixNum++;
            dataLoc = 0;
            stage = 0;
            cleanString(dataHolder);
            i = 0;
        }
        if(inChar != EOF){
            inChar = getc(fp);
        }
    }
    fclose(fp);
    printf("Session successfully loaded from %s.\n", file);
    return matrixNum;
}

void clearInputBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF){}
}

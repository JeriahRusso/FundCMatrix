#include <stdio.h>

struct matrix{
    char names[][];
    float data[][];
};
typedef struct matrix matix_t;

int login();
void printMenu();
float[][] generateMatrix();
float[][] readMatrixFromFile(char* fileLocation);
float dotProduct(float[][] mat1, float[][] mat2);

int main(void){

    return 1;
}

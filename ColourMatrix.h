/*
 *          Matrix Manipulation Header File for:
 *          Programming Fundamentals with C Assessment Task 3 - Group Assessment
 *
 *          ColourMatrix.h
 */




/* List of font and background colour combinations used by printMatrix */
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[37;41m"
#define KGRN  "\x1B[37;42m"
#define KYEL  "\x1B[37;43m"
#define KBLU  "\x1B[37;44m"
#define KMAG  "\x1B[37;45m"
#define KCYN  "\x1B[37;46m"
#define KWHT  "\x1B[30;47m"
#define MAX_MATRICES 100

/* Name of the db file */
#define DB_NAME "db.txt"
#define MAX_FILE_NAME 50

struct matrix{
    char matrixName[MAX_FILE_NAME];
    int rows;
    int columns;
    float* data;
};
typedef struct matrix matrix_t;

matrix_t matrices[MAX_MATRICES];

/* Creates a matrix by returning a 2d array of the dimensions matrix[rows1][cols1]
 *
 * This function asks for user input for number of rows and columns, then returns a 2d array of matching dimensions.
 *
 * rows1 and cols1 are int* values that get updated and are used by other functions such as printMatrix
 */

extern int create_matrix(matrix_t* matrixP, int matrixLocation);

 /*extern float* create_matrix(int * cols1, int* rows);*/

/* Frees any allocated memory for the supplied matrix */
extern int deleteMatrix(float * mtx);

/* Uses a nested loop to cycle through each row and column, printing each value as it goes
 *
 * Before landing on the value it is about to print, this function changes the background colour and font colour (there are 8 colour combinations
 * that it cycles through)
 */
extern int printMatrix(matrix_t* our_matrix, int number_of_matrices);


int setValues(matrix_t* our_matrix, int number_of_matrices);

int addMatrix(matrix_t* our_matrix, int matrix_index1, int matrix_index2, int number_of_matrices);

int subtractMatrix(matrix_t* our_matrix, int matrix_index1, int matrix_index2, int number_of_matrices);

void showMatrixNames(matrix_t* matrix, int number_of_matrices);

int dotProductMatrix(matrix_t* our_matrix, int matrix_index1, int matrix_index2, int number_of_matrices);

void saveSessionToFile(matrix_t* matrices, int number_of_matrices, char* fileName);

/*Returns the number of matrices loaded*/
int loadSessionFromFile(matrix_t* matrix, char* file);

/*Cleans a char[] to all 0*/
void cleanString (char* string);

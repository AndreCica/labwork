#ifndef _MATRIX_H
#define _MATRIX_H 

/* Data structure */ 

typedef struct {
    unsigned int rows;
    unsigned int cols;
    double **element;
} Matrix;

/* Interfaces */

Matrix createMatrix(const unsigned int nRows, const unsigned int nCols);
Matrix createMatrixFromFile(const char *filename);
void destroyMatrix(Matrix mat);
void printMatrix(const Matrix mat);

#endif

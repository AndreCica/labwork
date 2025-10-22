#ifndef _VECTOR_H//oh so this all checks if a macro has been defined, then defines a macro to make sure that the header file is being put in once and once only
#define _VECTOR_H

/* Data structure */ 

typedef struct {
    unsigned int length;
    double *element;
} Vector;

/* Interfaces */

Vector createVector(const unsigned int nLength);
Vector createVectorFromFile(const char *filename);
void destroyVector(Vector vec);
void printVector(const Vector vec);

#endif

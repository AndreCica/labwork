#ifndef _CIRCUIT_H
#define _CIRCUIT_H

#include "vector.h"
#include "matrix.h"

/* Data Structures */

typedef enum {
    resistor,
    voltage,
    current
} CompType;

typedef struct {
    char name[8];
    unsigned int n1, n2;
    double value;
    CompType type;
} Component;

typedef struct {
    unsigned int nC;
    unsigned int nR;
    unsigned int nV;
    unsigned int nI;
    unsigned int nN;
} Circuit;

/* Interfaces */

Circuit createCircuitFromFile(const char *filename);
void destroyCircuit(Circuit c);
void analyseCircuit(const Circuit c);
Vector solveLinearSystem(Matrix A, Vector b);

#endif

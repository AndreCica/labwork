#include <iostream>
#include <cmath>
#include <string>//bro let me live
#include <vector>
#ifndef MATRIX_H
#define MATRIX-H

class Matrix{
private:
    int numRows;
    int numCols;
    std::vector<std::vector<double>> values; //try to make this the main one

public:
    Matrix(int a, int b){
        numRows = a;
        numCols = b;
        values = std::vector<std::vector<double>>(numRows, std::vector<double>(numCols, 0));
    };
    Matrix(std::vector<std::vector<double>> c){
        numRows = c.size();
        numCols = c[0].size();
        values = c;
    }

    void printMatrix(){
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < numCols; j++){
                std::cout << values[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void setMatrix(std::vector<std::vector<double>> a){
        values = a;
        //im not completely sure if this is necessary anymore
    }

    Matrix copyMatrix(Matrix mat){//remember that Matrix is the return type
        Matrix copyMat(mat.numRows, mat.numCols);
        copyMat.values = mat.values;
        //im not sure if it is necessary to copy over the numRows and numCols if the values are ther
        //ig you would end up having to construct it manually to do that again which might be a hassle at runtime
        copyMat.numRows = mat.numRows;
        copyMat.numCols = mat.numCols;
        return copyMat;
        //i think this still works cause you have the function you are calling from which you wanna change
        //and the argument is the one you wanna change it to
        //like if you have a empty newMat and you wanna put 
        //check if you should do passing by reference in this one
    }

    Matrix operator*(const Matrix& matB){//matrix to matrix multiplication
        //const makes sure that you wont avoid copying
        //you replaced matA.anything with anything cause of the this thing
        //passing by reference just tends to save a bit of time
        Matrix solution(numRows, matB.numCols);
        if(numCols == matB.numRows){
            for (int i = 0; i < numRows; i++){//as long as theres still rows in A (the ones going down)
                for(int j = 0; j < matB.numCols; j++){//as long as theres columns
                    for(int k = 0; k < numCols; k++){//columns in A and rows in B i think
                        solution.values[i][j] += values[i][k] * matB.values[k][j];
                    }
                }

            }
        }
        else{
            std::cout << "Error: Your matrices cannot me multiplied :(";
        }
        return solution;
        //if you feel like it you can change this for a more efficient algorithm later
    }

    Matrix operator*(const double& scalar){//scalar to matrix multiplication
        Matrix solution(numRows, numCols);//this is cause multiplying by a scalar doesnt change the dimensions
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < numCols; j++){
                solution.values[i][j] = solution.values[i][j] * scalar;
            }
        }
        return solution;
    }

    Matrix operator+(const Matrix& matB){//matrix addition
        Matrix solution(numRows, numCols);
        if(numRows == matB.numRows && numCols == matB.numCols){
            for(int i = 0; i < numRows){
                for(int j = 0; j < numCols; j++){
                    solution.values[i][j] = values[i][j] + matB.values[i][j];
                }
            }
        }
        else{
            std::cout << "Your matrices cannot be added :(\n";
        }
        return solution;
    }

};

#endif







    //regarding operator overloading, remember that it is defined within a class so that you can do ma
    //so for you it would be Matrix operator*(vector-vector-double weightMat, vector-vector-double mat2) would allow you to do matrix multiplication
    //while you could do another one for matrix scalar multiplication
    //i have this feeling that the setmatrix function is doing absolutely nothing, idk it felt like i was supposed to put it in
        //acc i think its only when you are trying to change you weight matrix



/*
------------------------stupid things i have done so far---------------------------

-in my constructor function i set int cols as a meaning that i was initializing a completely new variable instead of just setting it like 
    i was supposed to
-thinking that a setting function took a function and set it as something else, and then realising thats acc exactly what it does
-i still have no clue what the vector is doing in the member variables pile
-all the matrix errors, i hope im just sleep deprived and not acc stupid




-------------------more things to do-----------------------------------------
*make a matrix multiplication and addition function using operator overloading
*start with research on operator overloading
-eventually it would be good to optimise the matrix multiplication function so that it takes less time, like the fancy ones that you found
    on wikipeida
-make it so that the initial values for the class, like the member variables are eventually the depth and width of the network maybe??
*you need to find out how to print the weightMatrix and solution one
*maybe you need to find a way to copy a matrix to somewhere new
*find out how you are supposed to deal with the matrix being returned, like can you save it to another matrix (maybe update the copy file)
    or maybe you can save it, idk if the copy matrix works then you are probably good to move on
    -maybe you are gonna need to copy it to somewhere else, or use it to update the other matrices like weight, bias etc
-sort out the error saving thing, like it shouldnt return a matrix if you multiply two invalid ones, the program should stop
-make a random number generator, for a generate random number matrix function given inputs
-make this a header file
-you need to make a transposer thingy



*/

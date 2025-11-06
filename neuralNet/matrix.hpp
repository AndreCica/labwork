#include <iostream>
#include <cmath>
#include <string>//bro let me live
#include <vector>
#include <ctime>
#ifndef MATRIX_H
#define MATRIX_H

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
    Matrix(std::vector<double> d){
        numRows = 1;
        numCols = d.size();
        values = std::vector<std::vector<double>>(1, d);
    }
    
    void printMatrix(){
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < numCols; j++){
                std::cout << values[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    void setMatrix(std::vector<std::vector<double>> a){
        values = a;
        //im not completely sure if this is necessary anymore
    }

    /*
    might be useful for dynamic allocation idk yet
    void setRandMatrix(int n, int rows, int cols, std::vector<std::vector<std::vector<double>>>& weightMats){
        std::srand(std::time(nullptr));
        double randWeight;
        //i think you can maybe go into the vector of the vector of the vector thing, take a number and set that as a values of a matrix
        //it must be void cause its just editing another array
        //if i pass by reference then it modifies oringinal, to pass by reference you do std::vector<int>& v where v is the vector

        //so we need to know the matrix in the list we will be editing, the rows and columns we wanna fill with random numbers, and obviously the vector we are changing
        for(int i = 0; i < weightMats[n].size(); i++){
            for(int j = 0; j < weightMats[n][0].size(); j++){
                randWeight = static_cast<double>(2 * std::rand()) / RAND_MAX;
                weightMats[n][i][j] = randWeight;
            }
        }
    }
*/
    
    Matrix setRandMatrix(){
        Matrix randomMat(numRows, numCols);
        std::srand(std::time(nullptr));
        double randWeight;
        //i think you can maybe go into the vector of the vector of the vector thing, take a number and set that as a values of a matrix
        //it must be void cause its just editing another array
        //if i pass by reference then it modifies oringinal, to pass by reference you do std::vector<int>& v where v is the vector

        //so we need to know the matrix in the list we will be editing, the rows and columns we wanna fill with random numbers, and obviously the vector we are changing
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < numCols; j++){
                randWeight = static_cast<double>(2 * std::rand()) / RAND_MAX;
                randomMat.values[i][j] = randWeight;
            }
        }
        return randomMat;
    }

    Matrix transposeMatrix(){
        Matrix flippedMat(numCols, numRows);
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < numCols; j++){
                flippedMat.values[j][i] = values[i][j];
            }
        }
        return flippedMat;
        //i have more of a feeling that im not going to need to specify the number of rows and columns every time
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
                solution.values[i][j] = values[i][j] * scalar;
            }
        }
        return solution;
    }

    Matrix operator+(const Matrix& matB){//matrix addition
        Matrix solution(numRows, numCols);
        if(numRows == matB.numRows && numCols == matB.numCols){
            for(int i = 0; i < numRows; i++){
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

std::vector<std::vector<std::vector<double>>> makeWeightMats (int n, int rows, int cols, int initialvalue = 0){
    std::vector<std::vector<std::vector<double>>>weightMats(n, std::vector<std::vector<double>>(rows, std::vector<double>(cols, initialvalue)));
    return weightMats;
    //this is gonna be a bit tricky when i have to do matrix algebra based on the matrix that is filled in this row here
    //i probably have to initialize it with random numbers from 0 to 1
}



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
*you need to find out how to print the weightMatrix and solution one
*maybe you need to find a way to copy a matrix to somewhere new
*find out how you are supposed to deal with the matrix being returned, like can you save it to another matrix (maybe update the copy file)
    or maybe you can save it, idk if the copy matrix works then you are probably good to move on
    *maybe you are gonna need to copy it to somewhere else, or use it to update the other matrices like weight, bias etc
*make this a header file


-sort out the error saving thing, like it shouldnt return a matrix if you multiply two invalid ones, the program should stop
-make a random number generator, for a generate random number matrix function given inputs
-you need to make a transposer thingy
-you need to make a loop that initializes a weightMatrix (given the arguemts of rows, columns, and matrix number)
-eventually it would be good to optimise the matrix multiplication function so that it takes less time, like the fancy ones that you found
    on wikipeida
-make it so that the initial values for the class, like the member variables are eventually the depth and width of the network maybe??



*/

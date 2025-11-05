#include <iostream>
#include <cmath>
#include <string>//bro let me live
#include <vector>

class Matrix{
private:
    int numRows;
    int numCols;
    std::vector<std::vector<double>> weightMat;
    std::vector<std::vector<double>> solutionMat;

public:
    Matrix(int a, int b){
        numRows = a;
        numCols = b;
        weightMat = std::vector<std::vector<double>>(numRows, std::vector<double>(numCols, 0));
        solutionMat = std::vector<std::vector<double>>(numRows, std::vector<double>(numCols, 0));
    };

    void printMatrix(int rows, int cols){
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < numCols; j++){
                std::cout << weightMat[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void setMatrix(std::vector<std::vector<double>> a){
        weightMat = a;
    }

    void multMat(std::vector<std::vector<double>> matA, std::vector<std::vector<double>> matB){
        int colA = matA.size();
        int rowB = matB[0].size();
        int rowA = matA[0].size();
        int colB = matB.size();
        if(rowA == colB){
            for (int i = 0; i < rowA, i++;){
                for(int j = 0; j < colB; j++){
                    for(int k = 0; k < colA; k++)//colA and rowB should be equal

                }

            }
        }
        else{
            std::cout << "Error: Your matrices cannot me multiplied :(";
        }
    }
};

int main() {
    int rowInput1, colInput1, rowInput1, colInput2;

    //testing the matrix multiplication thing



    std::cout << "Hello World!" << "\n";
    std::cout << "what rows and columns would you like in your matrix?\n";
    std::cin >> rowInput1 >> colInput1;

    Matrix firstmat(rowInput1, colInput2);
    //firstmat.printMatrix(rowInput, colInput);
    std::vector<std::vector<double>> mat1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<std::vector<double>> mat2 = {{4, 1, 5}, {9, 2, 6}, {5, 3, 5}};

}







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



-------------------more things to do-----------------------------------------
-make a matrix multiplication and addition function using operator overloading
-start with research on operator overloading
*/

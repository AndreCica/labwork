#include <iostream>
#include <cmath>
#include <string>//bro let me live
#include <vector>

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

    void printMatrix(std::vector<std::vector<double>> d){
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < numCols; j++){
                std::cout << d[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void setMatrix(std::vector<std::vector<double>> a){
        values = a;
    }

    Matrix multMat(Matrix matA, Matrix matB){
        Matrix solution(matA.numRows, matB.numCols);
        if(matA.numCols == matB.numRows){
            for (int i = 0; i < matA.numRows; i++){//as long as theres still rows in A (the ones going down)
                for(int j = 0; j < matB.numCols; j++){//as long as theres columns
                    for(int k = 0; k < matA.numCols; k++){//columns in A and rows in B i think
                        solution.values[i][j] += matA[i][k] * matB[k][j];
                    }
                }

            }
        }
        else{
            std::cout << "Error: Your matrices cannot me multiplied :(";
        }
        return solution;
    }
    //if you feel like it you can change this for a more efficient algorithm later


};

int main() {
    int rowInput1, colInput1, rowInput2, colInput2;

    std::cout << "Hello World!" << "\n";
    std::cout << "what rows and columns would you like in your matrix?\n";
    std::cin >> rowInput1 >> colInput1;

    Matrix firstmat(rowInput1, colInput2);

    std::vector<std::vector<double>> mat1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<std::vector<double>> mat2 = {{4, 1, 5}, {9, 2, 6}, {5, 3, 5}};
    firstmat.multMat(mat1, mat2);
    firstmat.printMatrix(3, 3);

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
-all the matrix errors, i hope im just sleep deprived and not acc stupid



-------------------more things to do-----------------------------------------
-make a matrix multiplication and addition function using operator overloading
-start with research on operator overloading
-eventually it would be good to optimise the matrix multiplication function so that it takes less time, like the fancy ones that you found
    on wikipeida
-make it so that the initial values for the class, like the member variables are eventually the depth and width of the network maybe??
-you need to find out how to print the weightMatrix and solution one



*/

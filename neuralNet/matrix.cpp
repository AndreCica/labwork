#include <iostream>
#include <cmath>
#include <string>//bro let me live
#include <vector>

using std::vector;

class Matrix{
private:
    //start with the constructor function, remember what to put inside one
    //a matrix[i][j] is i rows and j columns
    
    


    std::vector<std::vector<double>> mat1;
    /*
    int createMatrix(int numRows, int numCols){
        for(int i = 0; i < numCols; i++){
            for(int j = 0; j < numRows; j++){//
                
            }
        }
    }

private:    
    -its a set number of rows but the columns are dependent on how many columns in the column (help)
    */
    


    int setMatrix(){
        std::vector<std::vector<double>> mat1();



        //do .rezise
    }


public:
    Matrix(int a, int b){
        int numRows = a;
        int numCols = b;
        std::vector<std::vector<double>>mat1(numRows, std::vector<double>(numCols, 0));
        
    };
    //regarding operator overloading, remember that it is defined within a class so that you can do ma
    //so for you it would be Matrix operator*(vector-vector-double mat1, vector-vector-double mat2) would allow you to do matrix multiplication
    //while you could do another one for matrix scalar multiplication



};










int main() {
    std::cout << "Hello World!";


    //youre bad practice
}



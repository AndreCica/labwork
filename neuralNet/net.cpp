#include <iostream>
#include <vector>
#include "matrix.hpp"
#include <cstdlib>
#include <random>
#include <ctime>

std::vector<int> setVector(int vector_length){
    std::vector<int>inputVec(vector_length);
    return inputVec;
}



int main(){
    int inputNum, neuronNum, weightNum, outputNum;
    double input1, input2;
    weightNum = neuronNum * inputNum;
    //we are just doing one layer for now

    std::cout << "How many inputs would you like?\n";
    std::cin >> inputNum; 
    std::cout << "how many neurons would you like in your hidden layer?\n";
    std::cin >> neuronNum;
    std::cout << "how many outputs would you like?\n";
    std::cin >> outputNum;
    /*
    std::cout << "You are using " << inputNum << "inputs, " << outputNum << "outputs, and " << neuronNum << "Neurons in your hidden layer\n";
    std::cout << "your input matrix is " << inputNum << "x" << "1" << "\n";
    std::cout << "your output matrix is " << outputNum << "x" << "1" << "\n";
    std::cout << "your input weight matrix is " << neuronNum << "x" << inputNum << "\n";
    std::cout << "your output weight matrix is " << outputNum << "x" << inputNum << "\n";
    */

    weightNum = neuronNum * inputNum;


    //okay so for

    //am i supposed to take the matrix from the long line of vectors of vectors of vectors or initialized
   
    Matrix inputMat(1, inputNum);
    Matrix weightMat1(neuronNum, inputNum);
    weightMat1 = weightMat1.setRandMatrix();
    Matrix weightMat2(outputNum, neuronNum);
    weightMat2 = weightMat2.setRandMatrix();
    Matrix bias1(neuronNum, 1);
    bias1 = bias1.setRandMatrix();
    Matrix bias2(outputNum, 1);
    bias2 = bias2.setRandMatrix();
    Matrix neuronMat(neuronNum, 1);
    Matrix outputMat(outputNum, 1);

    std::cout << "What would you like your 2 inputs to be\n";
    std::cin >> input1 >> input2;
    
    
    //remember to allow for multiple inputs soon
    std::vector<double>inMat = {input1, input2};
    inputMat = inMat;

    //this is the start of the feed forward - layer1
    inputMat = inputMat.transposeMatrix();
    neuronMat = (weightMat1 * inputMat) + bias1;
    neuronMat.printMatrix();
    neuronMat = neuronMat.sigmoid();
    neuronMat.printMatrix();

    //layer2
    outputMat = (weightMat2 * neuronMat) + bias2;
    outputMat.printMatrix();
    outputMat = outputMat.softmax();
    outputMat.printMatrix();

    

    return 0;



}
/*
int main() {
    int rowInput1, colInput1, rowInput2, colInput2;

    std::cout << "Hello World!" << "\n";
    //std::cout << "what rows and columns would you like in your matrix?\n";
    //std::cin >> rowInput1 >> colInput1;

    Matrix mat1(std::vector<std::vector<double>> {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});//this constructs the matrix
    Matrix mat2(std::vector<std::vector<double>> {{4, 1, 5}, {9, 2, 6}, {5, 3, 5}});
    //this stems from a misunderstanding on the relationship between the 2d vectors and the matrix objects
    //a mat object is not a matrix in itself, but it contains a matrix in its value variable, a variable which is an array or smth like that

    Matrix solMat = mat1 * mat2;//i think this solves the issue about the returning value, cause you set it as something else right here
    //solMat has got everything you need, and since you made it in runtime its here as long as you want as well

    solMat.printMatrix();

    

    //you can define a matrix c as the solution of a multiplied by b, it feels so easy but so out of reach :(
}
*/


/*---------------what was hard------------
- the first thing im struggling to understand is how im able to make the neural network scalable
    -its the same thing from the previous lab that im trying to make it so that you can pass a fillable variable into a matrix
-you still dont understand the backpropagation algorithms and how exactly the weights are changed using the error
-with calculating the layers could it be more efficient to calculate second derivative as well to try and find a lowest point?
    -worth extra research
-maybe its the learning rate that changes based on the second derivative



-----------------------things to do-----------------------------------

-you need to find out how to make a function that can take an input and make this specific number of weight matrices so that everything 
    is dynamic
-you still dont fully understand the equations you are gonna need for back propagation
-initialize the vectors with random numbers cause its probably better than 0

-find out if you need to 
-in main take all inputs and use it to set a input matrix size, weight matrix size, 
-you should now make a program in main that initializes the matrices for the input matrix, input weight matrix, output weight matrix and output weight
    -you can even do it from a set input and output combination, or stuff in the code
    -afterwards you should make it completely automatic based on inputs
-find out how to do the thing from before with std::function and lambda to pass a function into the program so u can switch sigmoid and shi
-you should set the input matrix using a loop and .pushback() so that you can add more inputs easily
    -also remember for the dynamic memory thing, it would probably work cause you have set input and output matrices, and the rest are equal size

-----simple todo----
-test random
-test matrix mult
-actually set up the feed forward


*/
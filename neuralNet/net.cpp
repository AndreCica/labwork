#include <iostream>
#include <vector>

std::vector<std::vector<std::vector<double>>> makeWeightMats (int n, int rows, int cols, int initialvalue = 0){
    std::vector<std::vector<std::vector<double>>>weightMats(n, std::vector<std::vector<double>>(rows, std::vector<double>(cols, initialvalue)));
    return weightMats;
    //this is gonna be a bit tricky when i have to do matrix algebra based on the matrix that is filled in this row here
    //i probably have to initialize it with random numbers from 0 to 1
}



int main(){
    std::cout << "Hello World!";
    return 0;
}



/*
- the first thing im struggling to understand is how im able to make the neural network scalable
    -its the same thing from the previous lab that im trying to make it so that you can pass a fillable variable into a matrix
    -like having variable y = 3x + 5 being passed into a vector of y1, y2, y3 and so on where x can still be defined as anything
    -i need this cause if a network has 3 inputs, then the weight matrix needs to have 3 columns
        -i dont even know think you need to predefine them using maths actually, youre prob good but its worth learning anyways
-make sure that youre allowed to multiply scalars by matrices in c++, otherwise its gonna get quite long (cause of dynamic allocation)
-what is the point of transposing the matrix
-you still dont understand the backpropagation algorithms and how exactly the weights are changed using the error
    -is the bias changed as well?
-with calculating the layers could it be more efficient to calculate second derivative as well to try and find a lowest point?
    -worth extra research
-maybe its the learning rate that changes based on the second derivative



-----------------------things to do-----------------------------------

-you need to find out how to make a function that can take an input and make this specific number of weight matrices so that everything 
    is dynamic
-you still dont fully understand the equations you are gonna need for back propagation
-initialize the vectors with random numbers cause its probably better than 0
*/
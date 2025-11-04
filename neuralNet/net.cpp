#include <iostream>

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
*/
#include <iostream>
#include <iomanip>//the thing with filling 0s is done here
#include <cmath>
#include <string>
#include <functional>

const double pi = 3.141592654;
const int width = 80;

class Plot{
private://here im setting internal variables, this means you cant change these variables anywhere outside this private section (it adds safety)
    double frequency;
    double phase;
public:
    std::function<double(double)> SineFunc = [](double x) {return std::sin(x); };
    std::function<double(double)> CosineFunc = [](double x) {return std::cos(x); };
    std::function<double(double)> TangentFunc = [](double x) {return std::tan(x); };
    std::function<double(double)> funcChosen; 
    //these 4 are basically defining lambdas using std::function. its a compact way of making it so you can pass a function as an argument
    //the idea is that the user selects one of these 4 functions, then i pass them in as my argument to the plotter function
    //its just more compact. you can equally just say if the user presses 1 then do sine

    Plot(double f, double p)//constructor function, initializes frequency and phase when the function is called
        : frequency(f), phase(p) {}

    void plotval(std::function<double(double)> a){
        //argument a is currently pointless cause you odo the funcChosen directly
        unsigned long x = 0;
        while(1){
            double y =  0.5 * funcChosen(frequency * x * (pi/180) + phase) + 0.5 ;

            std::cout << "x: " << std::setfill ('0') << std::setw(7) << x;      
            std::cout << "  y: " << std::fixed << std::setprecision(4) << y;//std::fixed is what is forcing the trailing zeros

            int space_num = y * width;//this finds the amount of spaces you need before putting the asterisk
            if((x + 45) % 90 == 0){//this puts dashes every 10 lines
                std::cout << "---";
            }
            else std::cout << "   ";
            for(int i = 0; i < space_num; i++){
                std::cout << " ";
            }
            std::cout << "*\n";//the actual asterisk you see that plots the wave
            x++;
        }
    }
    void setfreq(double newFreq){frequency = newFreq;}
    void setphase(double newPhase){phase = newPhase;}
    //these functions allow you to set the private variables from the plot class (if you try and set frequency = 30; in the code it wont work)

    void chooseFunc(int choice){
        switch(choice){
        case 1: funcChosen = SineFunc; break;
        case 2: funcChosen = CosineFunc; break;
        case 3: funcChosen = TangentFunc; break;
        }
    }
};

int main(){
    int inputFunc, inputFreq, inputPhase;

    std::cout << "Please select a function, frequency and phase" << std::endl;
    std::cout << "1:   sine\n2:   cosine\n3:   tangent" << std::endl;
    std::cin >> inputFunc >> inputFreq >> inputPhase;

    Plot func1(inputFreq, inputPhase);
    func1.chooseFunc(inputFunc);
    func1.plotval(func1.funcChosen);

    return 0;
}

/*
--------------things to research/general notes---------------

-find out about what lambdas are
    okay i think it is a one line function you can define without naming
    good when you wanna pass a function in as an argument or store in a variable
    i guess i could make a whole function that gives the return function from c and then set that as an argument
    [capture](parameters) -> return_type{}
-actually understand what the way to do static cast is
-whats a constructor
    a function with the same name as the name of the class, its meant to initialize month and day to arguments
    no arguments are returned, no type
    yeah it just sets variables inside i think, like do 3 random arguments and set ur important variables to those
-whats the thing with putting :: between class and function, i thought it was a .


-find out what the class is supposed to contain. im thinking that the instance that you call will us will just be func1
    that being the first input that the person gives of what function they want
    this is prob valid cause ill use it again in the fourier transoform, it just approximates a wave
    now you have to find out how to call a function and set a function as a variable

-remember that OutputFunc is just gonna be a parameter for you to later put in input (like SineFunc)



    ---lambda and std::func---
    
    //before the equals its a new variable that can hold any callable function (double to double if you remember)
    //[](...){...} is a lambda which helps you to write a function inline
    //the lambda takes one argument in the regular brackets (double x) 
    //the return is curly {} and gives what is being returned
    //gpt wants me to do static cast as well :(
    //wait it literally converts a type to another (runs at compile time so its much safer)



    ------things to do-----------
    -need to make setter functions for all private variables (probably useful in the fourier bit)
    -youre gonna try to save a bit of time with a switch thingy which is pretty much like case in systemverilog
    -plot more interesting functions
    -add noise
    -do fourier with number of harmonics
    -make it sleep for a bit so you can keep track
    -clean up tan with limits
    -make it so the function arguments arent being useless
*/
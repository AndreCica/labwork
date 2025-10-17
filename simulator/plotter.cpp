#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <functional>

//main issues are that arguments in functions are not being used and there some safety additions that would be good

const double pi = 3.141592654;
const int width = 80;
float freq_chosen;

class Plot{
private://internal variables, this means you cant change these variables anywhere outside this private section (adds safety)
    double frequency;
    double phase;

public:
    std::function<double(double)> SineFunc = [](double x) {return std::sin(x); };//sets an std::func MyFunc as a lambda(mini mystery function)
    std::function<double(double)> CosineFunc = [](double x) {return std::cos(x); };
    std::function<double(double)> TangentFunc = [](double x) {return std::tan(x); };
    std::function<double(double)> funcChosen; //this is just storage, well set the above to funcChosen then plotval(funcChosen)

    Plot(double f, double p)//constructor function
        : frequency(f), phase(p) {}

    int plotval(std::function<double(double)> a){//why not a lambda i dont know
        //okay this is the function which x is local to
        //when i pass set_y in here the same x is being used
        //funcChosen is what will pass through here, as well as a x=0 default
        //argument a is currently pointless cause you odo the funcChosen directly
        unsigned long x = 0;
        while(1){
            double y =  0.5 * funcChosen(frequency * x * (pi/180) + phase) + 0.5 ;
            std::cout << "x: " << std::setfill ('0') << std::setw(7) << x;      
            std::cout << "  y: " << std::fixed << std::setprecision(4) << y;//std::fixed is what is forcing the trailing zeros
            int space_num = y * width;//truncates multiplication to find the number of spaces
            if((x + 45) % 90 == 0){//the labelled line thingy they asked for some reason
                std::cout << "---";
            }
            else std::cout << "   ";
            for(int i = 0; i < space_num; i++){
                std::cout << " ";
            }
            std::cout << "*\n";//the actual asterisk you see
            x++;
        }
    }
    void setfreq(double newFreq){frequency = newFreq;}
    void setphase(double newPhase){phase = newPhase;}

    void chooseFunc(int choice){//func chosen shouldnt be an int, remember with std::function you can store functions in variables
        switch(choice){//"choice" is what is being compared to all of the numbers, funcChosen stores the result for us to then plot the correct function
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

//whats left

//plot more interesting functions
//add phase properly
//add noise
//do tan or something like that
//do fourier with number of harmonics
//make it sleep for a bit so you can keep track

//could i fuse funcOutput with funcChosen? wait does funcOutput as a name serve any purpose (like could i just call it a)

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
    -need to make that function they talked about in leture where all the variables are manually called (good practise)
    -need to make setter functions for all private variables (probably useful in the fourier bit)
    -youre gonna try to save a bit of time with a switch thingy which is pretty much like case in systemverilog







*/
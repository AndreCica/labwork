#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <functional>


unsigned long x = 135;
const double pi = 3.1415926;
//note that y = sin(x * (pi/180))
float y = 0.5 * sin(x * (pi/180)) + 0.5;
const int width = 80;
float freq_chosen;



//so if you do MyFunc(x) its gonna sin it
    //i think this sets a function that enters and exits with a double number
    //


//start trying to get classes going


class plot{
private://internal variables, this means you cant change these variables anywhere outside this private section (adds safety)
    double frequency;
    double phase;
public:
    std::function<double(double)> SineFunc = [](double x) {return std::sin(x); };//sets an std::func MyFunc as a lambda(mini mystery function)
    std::function<double(double)> CosineFunc = [](double x) {return std::cos(x); };
    std::function<double(double)> TangentFunc = [](double x) {return std::tan(x); };

    int plotval1(std::function<double(double)> f){
        //gpt says i dont need to pass phase and frequency i can still use them here

    }
    void setfreq(){

    }
    void setphase(){

    }
    
    //since the frequency and phase are being put in private i should make caller functions for freq and phase
};

int plotval(float range, int width){
    //you get the range and multiply it by the width, and then truncate it
    int space_num = range * width;
    if ((x+45) % 90 == 0){
        std::cout << "---";
    }
    else std::cout << "   ";
    for(int i = 0; i < space_num; i++){
        std::cout << " ";
    }
    std::cout << "*\n";
    return 0;
}
int printsin(float freq){
    while(1){
        //in order to print the first n characters of an unsigned long integer we first need to convert it to a string
        //acc no you just use the setw function, std::setw(6)
        //note setw will be ignored if the number is too big
        //note double quotes is a string literal and single quotes is a character literal, i didn't know that

        std::cout << "x: " << std::setfill ('0') << std::setw(7) << x;
        //std::fixed is what is forcing the trailing zeros
        std::cout << "  y: " << std::fixed << std::setprecision(4) << y;
        x++;
        y = 0.5 * sin(freq * x * (pi/180)) + 0.5;

        plotval(y, width);
    }
}

int printcos(float freq){
    while(1){
        //in order to print the first n characters of an unsigned long integer we first need to convert it to a string
        //acc no you just use the setw function, std::setw(6)
        //note setw will be ignored if the number is too big
        //note double quotes is a string literal and single quotes is a character literal, i didn't know that

        std::cout << "x: " << std::setfill ('0') << std::setw(7) << x;
        //std::fixed is what is forcing the trailing zeros
        std::cout << "  y: " << std::fixed << std::setprecision(4) << y;
        x++;
        y = 0.5 * cos(freq * x * (pi/180)) + 0.5;

        plotval(y, width);
    }
}


int main(){


    std::cout << "Please select a function" << std::endl;
    std::cout << "1:   sine\n2:   cosine" << std::endl;
    std::cin >> func_type;

    if (func_type == 1){
        std::cout << "What would you like as your frequency?";
        std::cin >> freq_chosen;
        printsin(freq_chosen);
    }
    else if(func_type == 2){//i should probably create a struct or something to avoid all the if statements, idk how to do that yet
        std::cout << "What would you like as your frequency?";
        std::cin >> freq_chosen;
        printsin(freq_chosen);
    }

    plot cosine


}

//whats left

//plot more interesting functions
//add phase properly
//add noise
//do tan or something like that
//do fourier with number of harmonics
//make it sleep for a bit so you can keep track

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







*/
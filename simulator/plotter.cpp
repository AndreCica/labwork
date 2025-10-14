#include <iostream>
#include <iomanip>
#include <cmath>


unsigned long x = 135;
const double pi = 3.1415926;
//note that y = sin(x * (pi/180))
float y = 0.5 * sin(x * (pi/180)) + 0.5;
int width = 80;
int func_type;
float freq_chosen;


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




}

//whats left

//plot more interesting functions
//add phase properly
//add noise
//do tan or something like that
//do fourier with number of harmonics
//make it sleep for a bit so you can keep track
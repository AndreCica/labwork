#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <string>

    int selected_row[9];
    int selected_col[9];
    int selected_cube[9];
    int sd_init[9][9];
    std::vector<int> unsolved;

    int sd_print(int a[9][9]){//this function prints the sudoku that has been passed as an argument
        std::cout << "=========================================\n";
        for (int i = 0; i < 9; i++) {
            if ((i % 3 == 0) && (i != 0)){
                std::cout << "||=====================================||\n";
            }
            std::cout << "||";
            for (int j = 0; j < 9; j++){              
                if ((j+1) % 3 == 0){
                    if (a[i][j] == 0){
                        std::cout << " - ||";
                        // here you should add the coordinates of the missing values into an array
                    }
                    else{
                        std::cout << " "<<  a[i][j] << " ||";
                    }
                }
               
                else if (a[i][j] == 0){
                    std::cout << " - |";
                    // here you should add the coordinates of the missing values into an array
                    }
                    else{
                    std::cout << " "<<  a[i][j] << " |";
                    }
            }
            std::cout << std::endl;
        }
        std::cout << "=========================================";
       
        return 0;
    }

    int sd_row(int a[9][9], int b){//take the elements of a row and put it in a matrix called selected_row
        memset(selected_row, 0, sizeof(selected_row));
        for(int i = 0; i < 9; i++){
            selected_row[i] = a[b][i];
        }
        return 0;
    }

    int sd_col(int a[9][9], int c){//take the elements of a column and put it in a matrix called selected_col
        memset(selected_col, 0, sizeof(selected_col));
        for(int i=0; i < 9; i++){
            selected_col[i] = a[i][c];
        }
        return 0;
    }

    int sd_cube(int a[9][9], int box_num){//takes in the matrix and the block number as arguments and creates a matrix of all the elements in a given block
        memset(selected_cube, 0, sizeof(selected_cube));
        int init_y_coord = (box_num / 3) * 3; //integer integration with truncation gives us the y coordinate of the box we want:)
        int init_x_coord = (box_num % 3) * 3;
        std::cout << "the x coord is: " << init_x_coord << "\n" << "the y coord is: "<< init_y_coord << "\n\n";
        int k = 0;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                selected_cube[k] = a[i + init_y_coord][j + init_x_coord];//this very likely does not work im just giving a shot of how the coords integrate
                std::cout << selected_cube[k] << " ";
                k++;
            }
        }
        return 0;

    }
    int sd_read() { //this reads the text file and pits it in a matrix called std_init
        std::ifstream file("easy.txt"); //file is just a name its not supposed to be std::file
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                file >> sd_init[i][j];
                //it might be smart to put guardrails of when to end things when the program has finished but oh well
                unsolved.push_back(i);
                unsolved.push_back(j);
            }
        }  
        return 0;
    }

    int sd_cube_coords(int box_num){// this takes the box number from 0 to 8 and get coords of the top left square of what will be an array for the lil box
        int init_x_coord = (box_num / 3) * 3; //integer integration with truncation gives us the x coordinate of the box we want:)
        int init_y_coord = (box_num % 3) * 3;
        std::cout << init_x_coord << "\n\n" << init_y_coord;


        return 0;
    }

    bool is_unit_valid(int unit[9]) {
        bool seen[10] = {false}; // index 0 is unused
        for (int i = 0; i < 9; i++) {
            int val = unit[i];
            if (val < 1 || val > 9) return false; // invalid number
            if (seen[val]) return false; // duplicate
            seen[val] = true;
        }
    return true;
    }

    bool sd_is_valid(int a[9][9]) {
    for (int i = 0; i < 9; i++) {
        // Check row
        for (int j = 0; j < 9; j++) {
            selected_row[j] = a[i][j];
        }
        if (!is_unit_valid(selected_row)) return false;

        // Check column
        for (int j = 0; j < 9; j++) {
            selected_col[j] = a[j][i];
        }
        if (!is_unit_valid(selected_col)) return false;

        // Check cube
        int start_row = (i / 3) * 3;
        int start_col = (i % 3) * 3;
        int k = 0;
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                selected_cube[k++] = a[start_row + r][start_col + c];
            }
        }
        if (!is_unit_valid(selected_cube)) return false;
    }

    return true; // All checks passed
    }


int main() {
    std::cout << "Welcome to Sudoku!\n";

    unsolved.reserve(81);
    sd_read(); // Load the puzzle from file

    while (true) {
        std::cout << "\nCurrent Board:\n";
        sd_print(sd_init);

        // Check if the board is fully and correctly solved
        if (sd_is_valid(sd_init)) {
            std::cout << "\nPuzzle is SOLVED and valid!\n" << "\n\n\nCONGRATULATIONS!!!!!\n";
            break;
        }

        int box_num;
        while (true) {
            std::cout << "\nSelect a 3x3 box (0-8), or -1 to quit: ";
            std::cin >> box_num;
            if (box_num == -1) {
                std::cout << "Quitting...\n";
                return 0;
            }
            if (box_num < 0 || box_num > 8) {
                std::cout << "Invalid box number. Try again.\n";
                continue;
            }
            break;
        }

        // Calculate the starting row and col of the box
        int start_row = (box_num / 3) * 3;
        int start_col = (box_num % 3) * 3;

        // Display the box contents in a 3x3 grid, showing '.' for empty cells
        std::cout << "\nBox " << box_num << " contents:\n";
        for (int i = 0; i < 3; ++i) {
            std::cout << "|| ";
            for (int j = 0; j < 3; ++j) {
                int val = sd_init[start_row + i][start_col + j];
                if (val == 0) {
                    std::cout << ". ";
                } else {
                    std::cout << val << " ";
                }
            }
            std::cout << "||\n";
        }

        int cell_num;
        while (true) {
            std::cout << "Select a cell inside box (0-8) to place your value, or -1 to quit: ";
            std::cin >> cell_num;
            if (cell_num == -1) {
                std::cout << "Quitting...\n";
                return 0;
            }
            if (cell_num < 0 || cell_num > 8) {
                std::cout << "Invalid cell number. Try again.\n";
                continue;
            }
            // Check if cell is empty
            int cell_row = start_row + (cell_num / 3);
            int cell_col = start_col + (cell_num % 3);
            if (sd_init[cell_row][cell_col] != 0) {
                std::cout << "That cell is already filled. Choose another.\n";
                continue;
            }
            break;
        }

        int value;
        while (true) {
            std::cout << "Enter value (1-9) to place in cell, or -1 to quit: ";
            std::cin >> value;
            if (value == -1) {
                std::cout << "Quitting...\n";
                return 0;
            }
            if (value < 1 || value > 9) {
                std::cout << "Invalid value. Try again.\n";
                continue;
            }
            break;
        }

        // Place the value
        int place_row = start_row + (cell_num / 3);
        int place_col = start_col + (cell_num % 3);
        sd_init[place_row][place_col] = value;
    }

    std::cout << "\nThanks for playing!\n";
    return 0;
}

/*
-----------------------------------------------------------------
This is just an example array printed  |
                                       V
-----------------------------------------------------------------


    int array1[9][9] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9}, {-1, 5, 6, 4, 5, 6, 7, 8, 9}, {7, 8, -1, 4, 5, 6, 7, 8, 9}, {1, 2, 3, 4, 5, 6, 7, 8, 9}, {-1, 5, 6, 4, 5, 6, 7, 8, 9}, {7, 8, -1, 4, 5, 6, 7, 8, 9}, {1, 2, 3, 4, 5, 6, 7, 8, 9}, {-1, 5, 6, 4, 5, 6, 7, 8, 9}, {7, 8, -1, 4, 5, 6, 7, 8, 9}
    };
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++){
            if (array1[i][j] == -1){
                std::cout << "_  ";
                // here you should add the coordinates of the missing values into an array
            }
            else{
                std::cout << array1[i][j] << "  ";
            }
        }
        std::cout << std::endl;

    }
   


}
*/




/*
-----------------------------------------------------------------
                            NOTES!!
-----------------------------------------------------------------
    //maybe lets start with an array


//okay lets start with a 3x3 soduko

-make an integer array
    -add in a -1 number function
    -put in an underscore for


    -wait maybe i make one large 9x9 array and manually construct abstract box and line

    -after a while try do do for loops for each 3 rows and columns in order to establish the boxes and lines

    -for taking in files remember to convert the space to the integer -1 so that they can be output as underscores in the main thing




*/

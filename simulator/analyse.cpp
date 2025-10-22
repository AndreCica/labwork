#include <iostream>
#include "circuit.hpp"

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        try {
            Circuit c(argv[1]);  // Create circuit from file
            c.analyseCircuit();   // Perform analysis
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return EXIT_FAILURE;
        }
    } 
    else 
    {
        std::cout << "Syntax: " << argv[0] << " <filename>" << std::endl;
    }

    return EXIT_SUCCESS;
}
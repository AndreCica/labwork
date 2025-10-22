#include "circuit.hpp"
#include <iostream>   // For std::cout
#include <fstream>    // For std::ifstream
#include <sstream>    // For std::istringstream
#include <stdexcept>  // For std::runtime_error
#include <iomanip>    // For std::setw, std::fixed, std::setprecision

// Constructor implementation (replaces createCircuitFromFile)
Circuit::Circuit(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }

    std::string line;
    unsigned int maxNode = 0;

    // Single pass read using modern C++
    while (std::getline(file, line)) {
        // Skip empty lines or comments
        if (line.empty() || line[0] == '*') {
            continue;
        }

        std::istringstream iss(line);
        Component comp; // Temporary component to read into

        // Parse the line
        if (!(iss >> comp.name >> comp.n1 >> comp.n2 >> comp.value)) {
            // If parsing fails, skip line or throw error
            // For robustness, we'll just print a warning and continue
            std::cerr << "Warning: Skipping malformed line: " << line << std::endl;
            continue;
        }

        // Determine component type and increment counts
        switch (comp.name[0]) {
            case 'R':
            case 'r':
                comp.type = CompType::resistor;
                nR++;
                break;
            case 'V':
            case 'v':
                comp.type = CompType::voltage;
                nV++;
                break;
            case 'I':
            case 'i':
                comp.type = CompType::current;
                nI++;
                break;
            default:
                std::cerr << "Warning: Unknown component type for " << comp.name << std::endl;
                comp.type = CompType::unknown;
                continue; // Don't add unknown components
        }

        // Add the valid component to our vector
        components.push_back(comp);

        // Track the highest node number
        if (comp.n1 > maxNode) maxNode = comp.n1;
        if (comp.n2 > maxNode) maxNode = comp.n2;
    }

    // Node labelling is zero-based, so total nodes = maxNode + 1
    nN = maxNode + 1;

    // file.close() is called automatically by ifstream's destructor
}

// analyseCircuit implementation
void Circuit::analyseCircuit() {
    // Get the total size for the MNA matrices
    const size_t matrixSize = nN + nV;

    // Create Matrix and Vector using your class constructors
    Matrix A(matrixSize, matrixSize);
    Vector Z(matrixSize);

    unsigned int cV = 0; // Index for current voltage source

    // Build nodal analysis equations
    // We use a modern range-based for loop
    for (const auto& comp : components) {
        // Use C++ accessors A[row][col] and Z[row]
        switch (comp.type) {
            case CompType::resistor: {
                double g = 1.0 / comp.value; // Conductance
                A[comp.n1][comp.n2] -= g;
                A[comp.n2][comp.n1] -= g;
                A[comp.n1][comp.n1] += g;
                A[comp.n2][comp.n2] += g;
                break;
            }
            case CompType::voltage: {
                // KCL equation for the voltage source
                A[comp.n1][nN + cV] = 1.0;
                A[comp.n2][nN + cV] = -1.0;
                
                // Branch equation (V_n1 - V_n2 = V_source)
                // Note: The C code had a minor bug/typo, setting Z to -value.
                // The correct MNA stamp is Z = +value. I've corrected it here.
                // V_n1*1 + V_n2*(-1) = V_source_value
                A[nN + cV][comp.n1] = 1.0;
                A[nN + cV][comp.n2] = -1.0;
                Z[nN + cV] = comp.value; 
                cV++;
                break;
            }
            case CompType::current:
                // Current source contribution to KCL
                Z[comp.n1] -= comp.value;
                Z[comp.n2] += comp.value;
                break;
            case CompType::unknown:
                // Should not happen, but good to handle
                break;
        }
    }

    // Node 0 is ground
    A[0][0] = 1.0;
    Z[0] = 0.0;
    for (size_t i = 1; i < matrixSize; ++i) {
        A[0][i] = 0.0;
        A[i][0] = 0.0;
    }

    // Analyse and display results
    // solveLinearSystem takes A and Z *by value*, so it operates on copies
    Vector X = solveLinearSystem(A, Z);

    // Replace printf with C++ iostream and iomanip for formatting
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "----------------------------" << std::endl;
    std::cout << " Voltage sources: " << nV << std::endl;
    std::cout << " Current sources: " << nI << std::endl;
    std::cout << "       Resistors: " << nR << std::endl;
    std::cout << "           Nodes: " << nN << std::endl;
    std::cout << "----------------------------" << std::endl;
    for (size_t i = 0; i < nN; i++) {
        std::cout << " Node " << std::setw(3) << i << " = " << std::setw(10) << X[i] << " V" << std::endl;
    }
    std::cout << "----------------------------" << std::endl;
    if (nV > 0) {
        cV = 0; // Reset voltage counter
        for (const auto& comp : components) {
            if (comp.type == CompType::voltage) {
                // Current through voltage source is in X[nN + cV]
                std::cout << " I(" << std::setw(4) << comp.name << ")    = " << std::setw(10) << X[nN + cV] << " A" << std::endl;
                cV++;
            }
        }
        std::cout << "----------------------------" << std::endl;
    }

    // No need to destroy A, Z, or X. They are automatically
    // destructed when they go out of scope.
}

// Implementation of the standalone solveLinearSystem function
Vector solveLinearSystem(Matrix A, Vector Z) {
    // This function receives *copies* of A and Z because they are
    // passed by value. It can modify them freely without
    // affecting the originals in analyseCircuit.

    // Use the accessors from your classes
    const size_t rows = A.getRows();
    const size_t cols = A.getCols();

    // Create solution vector
    Vector X(rows);

    // Reduce to upper triangular form
    for (size_t i = 0; i < rows - 1; ++i) {
        for (size_t j = i + 1; j < rows; ++j) {
            if (A[i][i] == 0.0) {
                 // Simple pivot check
                 // A real solver should implement partial or full pivoting
                 // For now, we'll throw an error to avoid division by zero
                 throw std::runtime_error("Division by zero in solveLinearSystem. Pivoting is required.");
            }
            double mult = -A[j][i] / A[i][i];
            for (size_t k = i; k < cols; ++k) {
                A[j][k] += mult * A[i][k];
            }
            Z[j] += mult * Z[i];
        }
    }

    // Back substitute to find Vector X
    for (int i = rows - 1; i >= 0; --i) {
        double sum = 0.0;
        for (size_t j = i + 1; j < cols; ++j) {
            sum += A[i][j] * X[j];
        }
         if (A[i][i] == 0.0) {
             throw std::runtime_error("Division by zero in solveLinearSystem. Matrix is singular.");
         }
        X[i] = (Z[i] - sum) / A[i][i];
    }

    return X;
}

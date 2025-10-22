#include "matrix.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

// Constructor with specific dimensions
Matrix::Matrix(size_t rows, size_t cols) 
    : elements(rows, std::vector<double>(cols, 0.0)) {
    // Creates 'rows' vectors, each of size 'cols' initialized to 0.0
}

// Constructor from file
Matrix::Matrix(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }
    
    std::string line;
    size_t expected_cols = 0;
    
    // First pass: determine dimensions
    while (std::getline(file, line)) {
        if (line.empty()) continue;  // Skip empty lines
        
        std::istringstream iss(line);
        double value;
        size_t col_count = 0;
        
        while (iss >> value) {
            col_count++;
        }
        
        if (col_count > 0) {
            if (expected_cols == 0) {
                expected_cols = col_count;
            } else if (col_count != expected_cols) {
                throw std::runtime_error("Inconsistent number of columns in file: " + filename);
            }
            elements.push_back(std::vector<double>());
        }
    }
    
    // Second pass: read the data
    file.clear();
    file.seekg(0);
    
    for (size_t i = 0; i < elements.size(); ++i) {
        std::getline(file, line);
        if (line.empty()) continue;
        
        std::istringstream iss(line);
        double value;
        while (iss >> value) {
            elements[i].push_back(value);
        }
    }
    
    if (file.bad()) {
        throw std::runtime_error("Error reading from file: " + filename);
    }
}

// Print function
void Matrix::print() const {
    for (size_t i = 0; i < elements.size(); ++i) {
        for (size_t j = 0; j < elements[i].size(); ++j) {
            std::cout << "[" << i << "][" << j << "] = " << elements[i][j] << "\n";
        }
    }
}

// Resize function
void Matrix::resize(size_t rows, size_t cols) {
    elements.resize(rows);
    for (auto& row : elements) {
        row.resize(cols, 0.0);
    }
}
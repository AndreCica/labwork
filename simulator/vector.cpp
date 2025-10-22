#include "vector.hpp"
#include <iostream>
#include <fstream>
#include <stdexcept>

// Constructor with specific length
Vector::Vector(size_t length) : elements(length, 0.0) {
    // elements(length, 0.0) creates a vector with 'length' elements, all initialized to 0.0
}

// Constructor from file
Vector::Vector(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }
    
    double value;
    while (file >> value) {
        elements.push_back(value);
    }
    
    if (file.bad()) {
        throw std::runtime_error("Error reading from file: " + filename);
    }
}

// Print function
void Vector::print() const {
    for (size_t i = 0; i < elements.size(); ++i) {
        std::cout << "[" << i << "] = " << elements[i] << "\n";
    }
}
/*
-----note example usage-----


#include "vector.hpp"
#include <iostream>

int main() {
    // Create vectors in different ways
    Vector v1;                    // Empty vector
    Vector v2(5);                 // Vector with 5 elements (all 0.0)
    Vector v3("data.txt");        // Vector from file
    
    // Access elements
    v2[0] = 3.14;
    v2[1] = 2.71;
    
    // Print
    std::cout << "Vector v2:\n";
    v2.print();
    
    // Get information
    std::cout << "Length: " << v2.length() << "\n";
    
    return 0;
}



--------------maths---------------------

// In the Vector class definition:
public:
    // Mathematical operations
    Vector& operator+=(const Vector& other);
    Vector operator+(const Vector& other) const;
    
    // Scalar operations
    Vector& operator*=(double scalar);
    Vector operator*(double scalar) const;
    
    // Utility functions
    double dot(const Vector& other) const;
    double norm() const;
    
    // Resize
    void resize(size_t new_length);

*/
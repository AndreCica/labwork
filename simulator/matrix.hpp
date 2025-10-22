#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <string>

class Matrix {
private:
    std::vector<std::vector<double>> elements;  // 2D vector - no manual memory management!

public:
    // Constructors
    Matrix() = default;
    explicit Matrix(size_t rows, size_t cols);
    explicit Matrix(const std::string& filename);
    
    // No need for destructor, copy constructor, or assignment operator!
    // Rule of Zero applies here too
    
    // Accessors
    size_t getRows() const { return elements.size(); }
    size_t getCols() const { return elements.empty() ? 0 : elements[0].size(); }
    bool empty() const { return elements.empty(); }
    
    // Element access
    std::vector<double>& operator[](size_t row) { return elements[row]; }
    const std::vector<double>& operator[](size_t row) const { return elements[row]; }
    double& operator()(size_t row, size_t col) { return elements[row][col]; }
    const double& operator()(size_t row, size_t col) const { return elements[row][col]; }
    
    // Operations
    void print() const;
    
    // Bonus: Resize functionality
    void resize(size_t rows, size_t cols);
};

#endif
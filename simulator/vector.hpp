#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <vector>
#include <string>

class Vector {
private:
    std::vector<double> elements;  // The magic ingredient!

public:
    // Constructors
    Vector() = default;  // Empty vector
    explicit Vector(size_t length);  // Vector with specific size
    explicit Vector(const std::string& filename);  // From file
    
    // No need for destructor, copy constructor, or assignment operator!
    // std::vector handles all memory management automatically
    
    // Accessors
    size_t length() const { return elements.size(); }
    bool empty() const { return elements.empty(); }
    
    // Element access
    double& operator[](size_t index) { return elements[index]; }
    const double& operator[](size_t index) const { return elements[index]; }
    
    // Operations
    void print() const;
    void push_back(double value) { elements.push_back(value); }
    void clear() { elements.clear(); }
    
    // Bonus: C++ iterators for range-based for loops
    auto begin() { return elements.begin(); }
    auto end() { return elements.end(); }
    auto begin() const { return elements.begin(); }
    auto end() const { return elements.end(); }
};

#endif
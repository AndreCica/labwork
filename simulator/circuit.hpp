#ifndef CIRCUIT_HPP
#define CIRCUIT_HPP

#include <string>
#include <vector>
#include "vector.hpp"
#include "matrix.hpp"

// Use enum class for type-safe enumerations
enum class CompType {
    resistor,
    voltage,
    current,
    unknown // Added for safety
};

// C++ struct for Component. std::string is used instead of char array.
struct Component {
    std::string name;
    unsigned int n1{0};
    unsigned int n2{0};
    double value{0.0};
    CompType type{CompType::unknown};
};

// The Circuit is now a class, encapsulating all its data
class Circuit {
private:
    // Member variables
    unsigned int nR{0}; // Number of resistors
    unsigned int nV{0}; // Number of voltage sources
    unsigned int nI{0}; // Number of current sources
    unsigned int nN{0}; // Number of nodes

    // Use std::vector to automatically manage component memory
    std::vector<Component> components;

public:
    // Constructor reads from file (replaces createCircuitFromFile)
    // Throws std::runtime_error on failure
    explicit Circuit(const std::string& filename);

    // No destructor needed! (Rule of Zero)
    // std::vector handles its own memory, replacing destroyCircuit

    // Main analysis function is now a member function
    void analyseCircuit();

    // --- Public "getter" functions ---
    // These allow other parts of your code to query the circuit's properties
    // in a read-only, safe way.

    size_t getResistorCount() const { return nR; }
    size_t getVoltageSourceCount() const { return nV; }
    size_t getCurrentSourceCount() const { return nI; }
    size_t getNodeCount() const { return nN; }
    size_t getComponentCount() const { return components.size(); }
};

// --- Standalone Helper Function ---

/**
 * @brief Solves a system of linear equations AX = Z using Gaussian elimination.
 * @param A The Matrix A. Passed by value, so a copy is made and modified.
 * @param Z The Vector Z. Passed by value, so a copy is made and modified.
 * @return Vector X, the solution.
 */
Vector solveLinearSystem(Matrix A, Vector Z);

#endif // CIRCUIT_HPP

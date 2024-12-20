#include <iostream>
#include <vector>
#include <stdexcept> // For exceptions

class Vector {
private:
    std::vector<double> elements;

public:
    // 1. Constructors
    Vector() {}
    Vector(int size) : elements(size) {}
    Vector(const std::vector<double>& elems) : elements(elems) {}

    // 2. Getters and Setters
    double get(int index) const { 
        if (index < 0 || index >= elements.size()) throw std::out_of_range("Index out of bounds");
        return elements[index]; 
    }
    void set(int index, double value) { 
        if (index < 0 || index >= elements.size()) throw std::out_of_range("Index out of bounds");
        elements[index] = value; 
    }

    size_t size() const { return elements.size(); } // Getter for size

    // 3. Overloaded Assignment Operator
    Vector& operator=(const Vector& other) {
        if (this != &other) { // Self-assignment check
            elements = other.elements;
        }
        return *this;
    }

    // 4. Overloaded Compound Assignment Operators
    Vector& operator+=(const Vector& other) {
        if (elements.size() != other.elements.size()) {
            throw std::invalid_argument("Vectors must be of the same size for addition.");
        }
        for (size_t i = 0; i < elements.size(); ++i) {
            elements[i] += other.elements[i];
        }
        return *this;
    }

    Vector& operator-=(const Vector& other) {
        if (elements.size() != other.elements.size()) {
            throw std::invalid_argument("Vectors must be of the same size for subtraction.");
        }
        for (size_t i = 0; i < elements.size(); ++i) {
            elements[i] -= other.elements[i];
        }
        return *this;
    }

    // 5. Overloaded Arithmetic Operators
    Vector operator+(const Vector& other) const {
        Vector result = *this;
        result += other;
        return result;
    }

    Vector operator-(const Vector& other) const {
        Vector result = *this;
        result -= other;
        return result;
    }

    // 6. Overloaded Multiplication Operators
    // Scalar multiplication (Vector * double)
    Vector operator*(double scalar) const {
        Vector result = *this;
        for (auto& elem : result.elements) {
            elem *= scalar;
        }
        return result;
    }

    // Dot product (Vector * Vector)
    double operator*(const Vector& other) const {
        if (elements.size() != other.elements.size()) {
            throw std::invalid_argument("Vectors must be of the same size for dot product.");
        }
        double scalarProduct = 0;
        for (size_t i = 0; i < elements.size(); ++i) {
            scalarProduct += elements[i] * other.elements[i];
        }
        return scalarProduct;
    }

    // 7. Overloaded Stream Operators
    friend std::ostream& operator<<(std::ostream& os, const Vector& vec) {
        os << "[";
        for (size_t i = 0; i < vec.elements.size(); ++i) {
            os << vec.elements[i];
            if (i < vec.elements.size() - 1) os << ", ";
        }
        os << "]";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Vector& vec) {
        std::cout << "Enter size of vector: ";
        size_t size;
        is >> size;

        vec.elements.resize(size);
        std::cout << "Enter " << size << " elements: ";
        for (auto& elem : vec.elements) {
            is >> elem;
        }
        return is;
    }
};

// Scalar multiplication (double * Vector)
Vector operator*(double scalar, const Vector& vec) {
    return vec * scalar;
}

// Testing the Vector class
int main() {
    try {
        Vector v1(3);
        Vector v2(3);

        std::cin >> v1;
        std::cin >> v2;

        std::cout << "Vector 1: " << v1 << std::endl;
        std::cout << "Vector 2: " << v2 << std::endl;

        // Addition
        Vector v3 = v1 + v2;
        std::cout << "v1 + v2: " << v3 << std::endl;

        // Subtraction
        Vector v4 = v1 - v2;
        std::cout << "v1 - v2: " << v4 << std::endl;

        // Scalar multiplication
        Vector v5 = v1 * 2;
        std::cout << "v1 * 2: " << v5 << std::endl;

        // Scalar product
        double dotProduct = v1 * v2;
        std::cout << "v1 * v2 (dot product): " << dotProduct << std::endl;

        // Scalar multiplication (double * Vector)
        Vector v6 = 3.0 * v2;
        std::cout << "3.0 * v2: " << v6 << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

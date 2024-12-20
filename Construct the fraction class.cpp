#include <iostream>
#include <numeric> // For std::gcd
#include <stdexcept>

class Fraction {
private:
    int numerator;
    int denominator;

    void simplify() {
        int gcd = std::gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
        if (denominator < 0) { // Ensure the denominator is positive
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    // Constructors
    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
        if (denom == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        simplify();
    }

    // Assignment operator
    Fraction& operator=(const Fraction& other) {
        if (this != &other) {
            numerator = other.numerator;
            denominator = other.denominator;
        }
        return *this;
    }

    // Getters and Setters
    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }
    void setNumerator(int num) { numerator = num; simplify(); }
    void setDenominator(int denom) {
        if (denom == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        denominator = denom;
        simplify();
    }

    // Convert to double
    double toDouble() const {
        return static_cast<double>(numerator) / denominator;
    }

    // Overloaded input and output operators
    friend std::ostream& operator<<(std::ostream& os, const Fraction& frac) {
        os << frac.numerator << "/" << frac.denominator;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Fraction& frac) {
        char slash;
        int num, denom;

        is >> num >> slash >> denom;

        if (is.fail() || slash != '/' || denom == 0) {
            is.setstate(std::ios::failbit);
            return is;
        }

        frac.numerator = num;
        frac.denominator = denom;
        frac.simplify();
        return is;
    }

    // Overloaded compound assignment operators
    Fraction& operator+=(const Fraction& other) {
        numerator = numerator * other.denominator + other.numerator * denominator;
        denominator *= other.denominator;
        simplify();
        return *this;
    }

    Fraction& operator-=(const Fraction& other) {
        numerator = numerator * other.denominator - other.numerator * denominator;
        denominator *= other.denominator;
        simplify();
        return *this;
    }

    Fraction& operator*=(const Fraction& other) {
        numerator *= other.numerator;
        denominator *= other.denominator;
        simplify();
        return *this;
    }

    Fraction& operator/=(const Fraction& other) {
        if (other.numerator == 0) {
            throw std::invalid_argument("Cannot divide by zero.");
        }
        numerator *= other.denominator;
        denominator *= other.numerator;
        simplify();
        return *this;
    }

    // Overloaded binary arithmetic operators
    friend Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
        Fraction result(lhs);
        result += rhs;
        return result;
    }

    friend Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
        Fraction result(lhs);
        result -= rhs;
        return result;
    }

    friend Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
        Fraction result(lhs);
        result *= rhs;
        return result;
    }

    friend Fraction operator/(const Fraction& lhs, const Fraction& rhs) {
        Fraction result(lhs);
        result /= rhs;
        return result;
    }
};

// Main function to test the implementation
int main() {
    Fraction frac1, frac2, result;
    char operation;

    // Prompt the user for input
    std::cout << "Enter the first fraction (e.g., 3/4): ";
    if (!(std::cin >> frac1)) {
        std::cerr << "Invalid input format for the first fraction!" << std::endl;
        return 1;
    }

    std::cout << "Enter the second fraction (e.g., 5/6): ";
    if (!(std::cin >> frac2)) {
        std::cerr << "Invalid input format for the second fraction!" << std::endl;
        return 1;
    }

    std::cout << "Enter the operation (+, -, *, /): ";
    std::cin >> operation;

    // Perform the operation
    try {
        switch (operation) {
            case '+':
                result = frac1 + frac2;
                break;
            case '-':
                result = frac1 - frac2;
                break;
            case '*':
                result = frac1 * frac2;
                break;
            case '/':
                result = frac1 / frac2;
                break;
            default:
                std::cerr << "Invalid operation!" << std::endl;
                return 1;
        }

        // Output the result
        std::cout << "Result: " << result << std::endl;
        std::cout << "Result as double: " << result.toDouble() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}


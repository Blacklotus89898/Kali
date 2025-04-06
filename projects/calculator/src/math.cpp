#include "math.hpp"
#include <stdexcept>

namespace math {
    double add(double a, double b) {
        return a + b;
    }

    double subtract(double a, double b) {
        return a - b;
    }

    double multiply(double a, double b) {
        return a * b;
    }

    double divide(double a, double b) {
        if (b == 0) {
            throw std::invalid_argument("Division by zero is not allowed.");
        }
        return a / b;
    }

    double power(double base, double exponent) {
        return std::pow(base, exponent);
    }

    double squareRoot(double value) {
        if (value < 0) {
            throw std::invalid_argument("Square root of a negative number is not defined.");
        }
        return std::sqrt(value);
    }
}
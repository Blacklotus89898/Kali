#include <iostream>
#include "math.hpp" // Include the math header

int main() {
    double a, b;
    char operation;

    // Prompt the user for input
    std::cout << "Enter an operation in the format: a operation b (e.g., 5 + 3): ";
    std::cin >> a >> operation >> b;

    // Perform the operation
    switch (operation) {
        case '+':
            std::cout << "Result: " << math::add(a, b) << std::endl;
            break;
        case '-':
            std::cout << "Result: " << math::subtract(a, b) << std::endl;
            break;
        case '*':
            std::cout << "Result: " << math::multiply(a, b) << std::endl;
            break;
        case '/':
            if (b != 0) {
                std::cout << "Result: " << math::divide(a, b) << std::endl;
            } else {
                std::cout << "Error: Division by zero is not allowed." << std::endl;
            }
            break;
        default:
            std::cout << "Error: Invalid operation." << std::endl;
            break;
    }

    return 0;
}
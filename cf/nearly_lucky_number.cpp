#include <iostream>
#include <string>

int main() {
    std::string number;
    std::cin >> number;

    int luckyDigitCount = 0;

    // Count occurrences of lucky digits (4 and 7)
    for (const char& digit : number) {
        if (digit == '4' || digit == '7') {
            luckyDigitCount++;
        }
    }

    // Check if the count itself is a lucky number
    while (luckyDigitCount > 0) {
        int digit = luckyDigitCount % 10;
        if (digit != 4 && digit != 7) {
            std::cout << "NO" << std::endl;
            return 0;
        }
        luckyDigitCount /= 10;
    }

    std::cout << "YES" << std::endl;
    return 0;
}

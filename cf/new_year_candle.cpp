#include <iostream>

int main() {
    int a = 0, b = 0;
    std::cin >> a >> b;

    int time = a; // Start with the initial number of candles
    while (a >= b) {
        int newCandles = a / b; // Calculate how many new candles can be made
        time += newCandles;    // Add the new candles to the total time
        a = newCandles + (a % b); // Update the number of candles left
    }

    std::cout << time << std::endl;
    return 0;
}

#include <iostream>

int main() {
    int n = 0;
    std::cin >> n;

    int odd_count = 0, even_count = 0;
    int last_even_index = 0, last_odd_index = 0;

    for (int i = 0; i < n; ++i) {
        int current_number;
        std::cin >> current_number;

        if (current_number % 2 == 0) {
            last_even_index = i + 1; // Store 1-based index directly
            ++even_count;
        } else {
            last_odd_index = i + 1; // Store 1-based index directly
            ++odd_count;
        }
    }

    // Output the index of the unique number
    std::cout << (odd_count == 1 ? last_odd_index : last_even_index) << std::endl;

    return 0;
}

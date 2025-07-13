#include <iostream>

int main() {
    int t = 0;
    std::cin >> t;

    while (t--) {
        int num = 0;
        std::cin >> num;

        bool found = false; // Flag to indicate if a solution is found

        for (int a = 2; a * a * a <= num; ++a) { // Optimize loop bounds
            if (num % a != 0) continue; // Skip if `a` is not a factor

            for (int b = a + 1; a * b * b <= num; ++b) { // Optimize loop bounds
                if (num % (a * b) != 0) continue; // Skip if `a * b` is not a factor

                int c = num / (a * b);
                if (c > b) { // Ensure a < b < c
                    std::cout << "YES" << std::endl;
                    std::cout << a << " " << b << " " << c << std::endl;
                    found = true;
                    break;
                }
            }

            if (found) break; // Break outer loop if solution is found
        }

        if (!found) {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}
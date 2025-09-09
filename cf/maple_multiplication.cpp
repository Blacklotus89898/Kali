#include <iostream>

int main() {
    int t = 0;
    std::cin >> t;
    while (t--) {


        int a, b;
        std::cin >> a >> b;

        if (a == b) {
            std::cout << 0 << std::endl;
        } else if ( a % b == 0 || b % a == 0) {
            std::cout << 1 << std::endl;
        } else {
            std::cout << 2 << std::endl;
        }
    }

    return 0;
}
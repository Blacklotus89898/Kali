#include <iostream>
#include <cmath>


int main() {

    int n = 0;
    std::cin >> n;

    if (n % 2 == 1) {
        std::cout << 0 << std::endl;
    } else {
        long long result = 0;
        result = std::pow(2, n / 2);
        std::cout << result << std::endl;
    }

    return 0;

}

// could do a stupid dp as well
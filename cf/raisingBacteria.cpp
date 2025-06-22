#include <iostream>
#include <cmath>

int main () {

    int n;
    std::cin >> n;

    int counter = 0;
    while(n > 0) {
        int power = 0;
        while(n >= pow(2, power)) {
            power++;
            // std::cout << n << " " << power - 1 << std::endl;
        }
        n -= pow(2, power - 1);
        counter++;
    }

    std::cout << counter << std::endl;

    return 0;
}
#include <iostream>

int main() {

    int n = 0;
    std::cin >> n;

    while(n != 1) {
        
        if (n % 2 == 0 ) {
            n /= 2;
        } else {
            n = 3*n + 1;
        }
        std::cout << n << std::endl;
    }


    return 0;
}
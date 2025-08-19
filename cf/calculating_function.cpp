#include <iostream>

#define ll long long

int main() {
    ll n = 0;
    std::cin >> n;

    ll result = 0;
    if (n % 2 == 0) {
        std::cout << n / 2 << std::endl; // even number
    } else {
        std::cout << n / 2 - n << std::endl; // odd number
    }

    return 0;

}
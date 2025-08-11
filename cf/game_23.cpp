#include <iostream>
#define ll long long

int main() {
    ll n, m;
    std::cin >> n >> m;

    if (m < n) {
        std::cout << "-1" << std::endl;
        return 0;
    } else {
        if (m % n != 0) {
            std::cout << "-1" << std::endl; //this edge case to be careful
            return 0;
        }
        ll move = 0;
        ll factor = m / n;
        while (factor % 2 == 0) {
            factor /= 2;
            move++;
        }
        while (factor % 3 == 0) {
            factor /= 3;
            move++;
        }

        // should never happen technically
        if (factor != 1) {
            std::cout << "-1" << std::endl;
            return 0;
        }
        std::cout << move << std::endl;
    }

    return 0;
}
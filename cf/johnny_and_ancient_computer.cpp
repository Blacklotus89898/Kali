#include <iostream>

#define ll long long

bool isPowerOfTwo(ll n) {
    return n > 0 && ((n & (n - 1)) == 0);
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        ll a, b;
        std::cin >> a >> b;

        ll high = std::max(a, b);
        ll low = std::min(a, b);

        if (high % low != 0) {
            std::cout << -1 << std::endl;
            continue;
        }

        ll factor = high / low;
        if (!isPowerOfTwo(factor)) {
            std::cout << -1 << std::endl;
            continue;
        }

        int expo = 0;
        while (factor > 1) {
            factor >>= 1;
            expo++;
        }

        int op = (expo + 2) / 3;
        std::cout << op << std::endl;
    }

    return 0;
}
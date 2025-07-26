#include <iostream>

int main() {

    int t = 0;
    std::cin >> t;

    while (t--) {

        int n = 0;
        int k = 0;
        std::cin >> n >> k;

        int mul = k > n ? 
        k : 
        k * (n / k + (n % k != 0 ? 1 : 0));

        int sum = mul / n + (mul % n != 0 ? 1 : 0);
        std::cout << sum << std::endl;
    }

    return 0;
}
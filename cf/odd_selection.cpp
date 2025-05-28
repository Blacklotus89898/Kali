#include <iostream>

int main() {
    int t = 0;
    std::cin >> t;

    while (t-- > 0) {
        int n = 0, x = 0;
        std::cin >> n >> x;

        int odd = 0;
        for (int i = 0; i < n; ++i) {
            int a = 0;
            std::cin >> a;
            if (a % 2 == 1) {
                odd++;
            }
        }

        if (odd == 0) {
            std::cout << "NO" << std::endl;
            continue;
        }

        if (x == n && odd % 2 == 0) {
            std::cout << "NO" << std::endl;
            continue;
        }

        int even = n - odd;
        bool can = false;

        // i is the number of odd elements we choose (must be odd)
        for (int i = 1; i <= odd && i <= x; i += 2) {
            if (x - i >= 0 && x - i <= even) {
                can = true;
                break;
            }
        }

        std::cout << (can ? "YES" : "NO") << std::endl;
    }

    return 0;
}

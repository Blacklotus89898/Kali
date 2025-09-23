#include <iostream>


int main() {

    int t = 0;
    std::cin >> t;

    while (t--) {
        long long x, y, k;

        // k torch == k stick + k coal
        // 1 coal = y stick
        std::cin >> x >> y >> k;

        long long res = (k*y + k -1 + x -2)/(x-1) + k;

        std::cout << res << std::endl;

    }


    return 0;
}
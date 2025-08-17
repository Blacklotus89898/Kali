#include <iostream>


int main() {

    int n = 0;
    std::cin >> n;

    int result = 0;
    for (int i = 0; i < n; ++i) {
        int p = 0, q = 0;
        std::cin >> p >> q;

        if (q - p >= 2) {
            result++;
        }   
    }

    std::cout << result << std::endl;
    return 0;
}
#include <iostream>

int main() {
    int t = 0;
    std::cin >> t;
    while (t--) {
        int a1, a2, b1, b2;
        std::cin >> a1 >> a2 >> b1 >> b2;

        int count = 0; //must consider the tie game
        if (a1 > b1 && a2 >= b2 || a1 >= b1 && a2 > b2) {
            count += 2;
        }
        if (a1 >= b2 && a2 > b1 || a1 > b2 && a2 >= b1) {
            count += 2;
        }

        std::cout << count << std::endl;
    }


    return 0;
}
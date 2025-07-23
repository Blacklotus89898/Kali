#include <iostream>

int main() {
    int n = 0;
    std::cin >> n;

    for(int i = 0; i < n; ++i) {
        int x = 0;
        std::cin >> x;
        if(x == 1) {
            std::cout << "HARD" << std::endl;
            return 0;
        }   
    }

    std::cout << "EASY" << std::endl;

    return 0;
}
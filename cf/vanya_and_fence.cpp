#include <iostream>
#include <vector>

int main() {

    int h = 0, n = 0, w = 0;
    
    std::cin >> n >> h;
    for(int i = 0; i < n; ++i) {
        int height = 0;
        std::cin >> height;
        height > h ? w += 2 : w += 1;
    }

    std::cout << w << std::endl;

    return 0;

}
#include <iostream>
#include <vector>

int main() {
    int n = 0;
    std::cin >> n;
    std::vector<int> a(7);

    for (int i = 0; i < 7; ++i) {
        std::cin >> a[i];
    }

    int index = 0;
    while (n > 0) {
        n -= a[index];
        if (n <= 0) {
            std::cout << index + 1 << std::endl; // +1 for 1-based index
            break;
        }
        index = (index + 1) % 7; // wrap around the week
    }





    return 0;
}
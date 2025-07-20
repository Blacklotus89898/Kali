#include <iostream>
#include <algorithm>

int main() {
    int n, curr = 0, cap = 0;
    std::cin >> n;

    while (n--) {
        int a, b;
        std::cin >> a >> b;
        curr += b - a; // Update current capacity
        cap = std::max(cap, curr); // Track maximum capacity
    }

    std::cout << cap << '\n';
    return 0;
}

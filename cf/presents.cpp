#include <iostream>
#include <vector>

int main() {

    int n = 0;
    std::cin >> n;
    std::vector<int> a(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        int x = 0;
        std::cin >> x;
        a[x] = i;
    }

    for (int i = 1; i <= n; ++i) {
        std::cout << a[i] << " ";
    }

    return 0;
}
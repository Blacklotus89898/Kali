#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int &val : a) std::cin >> val;

    std::sort(a.begin(), a.end());

    if (k == 0) {
        // x must be < smallest element
        if (a[0] == 1) {
            std::cout << -1 << std::endl;
        } else {
            std::cout << a[0] - 1 << std::endl;
        }
        // when sorted the value after must be different otherwise if violates
        // the constraint
    } else if (k == n || a[k - 1] != a[k]) {
        // Either we take max element, or the next one is strictly greater
        std::cout << a[k - 1] << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }

    return 0;
}

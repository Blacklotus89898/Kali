#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t = 0;
    std::cin >> t;

    while (t--) {
        int n = 0;
        std::cin >> n;

        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        int left = 0, right = n - 1;

        // Find the first position where the value changes from the start
        while (left < n - 1 && a[left] == a[0]) {
            ++left;
        }

        // Find the first position where the value changes from the end
        while (right > 0 && a[right] == a[n - 1]) {
            --right;
        }

        if (a[0] == a[n - 1]) {
            std::cout << std::max(0, right - left + 1) << std::endl;
        } else {
            std::cout << std::max(n - left - 1, right) << std::endl;
        }
    }

    return 0;
}

#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> piles(n);
    int acc = 0;

    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        acc += a;
        piles[i] = acc;
    }

    int m;
    std::cin >> m;
    while (m--) {
        int b;
        std::cin >> b;

        int left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (piles[mid] < b)
                left = mid + 1;
            else
                right = mid;
        }

        std::cout << left + 1 << '\n'; // 1-indexed pile number
    }

    return 0;
}

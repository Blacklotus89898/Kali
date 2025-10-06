#include <iostream>
#include <vector>
#include <limits>
#include <string>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> v(n);
        for (int& x : v) std::cin >> x;

        std::string s(n, '0');
        int min_so_far = std::numeric_limits<int>::max();
        for (int i = 0; i < n; ++i) {
            min_so_far = std::min(min_so_far, v[i]);
            if (v[i] == min_so_far) s[i] = '1';
        }

        int max_so_far = std::numeric_limits<int>::min();
        for (int i = n - 1; i >= 0; --i) {
            max_so_far = std::max(max_so_far, v[i]);
            if (v[i] == max_so_far) s[i] = '1';
        }

        std::cout << s << '\n';
    }

    return 0;
}
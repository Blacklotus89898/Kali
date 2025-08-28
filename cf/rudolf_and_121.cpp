#include <iostream>
#include <vector>

#define ll long long

int main() {
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);

    int t = 0;
    std::cin >> t;

    while (t--) {
        int n = 0;
        std::cin >> n;

        std::vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        bool valid = true;
        for (int i = 0; i < n - 2; ++i) {
            if (a[i] > 0) {
                ll reduce = a[i];
                a[i + 1] -= 2 * reduce;
                a[i + 2] -= reduce;
            }
            if (a[i + 1] < 0 || a[i + 2] < 0) {
                valid = false;
                break;
            }
        }

        if (valid && a[n - 2] == 0 && a[n - 1] == 0) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}

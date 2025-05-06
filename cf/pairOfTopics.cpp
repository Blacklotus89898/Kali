#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

int main() {
    int n;
    std::cin >> n;
    std::vector<ll> va(n), vb(n), diff(n);
    
    for (int i = 0; i < n; ++i) std::cin >> va[i];
    for (int i = 0; i < n; ++i) {
        std::cin >> vb[i];
        diff[i] = va[i] - vb[i];
    }

    // n log n
    std::sort(diff.begin(), diff.end());
    ll res = 0;

    // 
    for (int i = 0; i < n; ++i) {
        // Custom upper_bound to find first index j > i such that diff[j] > -diff[i]
        int l = i + 1, r = n;
        // bninary search
        while (l < r) {
            int m = (l + r) / 2;
            if (diff[m] > -diff[i]) r = m;
            else l = m + 1;
        }
        res += n - l;
    }

    std::cout << res << '\n';
    return 0;
}

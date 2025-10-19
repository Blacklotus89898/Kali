#include <iostream>
#include <vector>

#define ll long long

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        if (i > 0) a[i] += a[i - 1];  // prefix sum
    }

    while (m--) {
        ll target;
        std::cin >> target;

        // Binary search for first index where a[i] >= target
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (a[mid] < target)
                l = mid + 1;
            else
                r = mid;
        }

        ll room = l + 1;
        ll offset = target - (l > 0 ? a[l - 1] : 0);
        std::cout << room << " " << offset << "\n";
    }

    return 0;
}
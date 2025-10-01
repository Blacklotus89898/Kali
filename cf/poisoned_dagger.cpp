#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        ll h;
        std::cin >> n >> h;
        std::vector<ll> v(n);
        for (int i = 0; i < n; i++) std::cin >> v[i];

        ll l = 1, r = h, ans = h;
        while (l <= r) {
            ll k = (l + r) / 2;
            ll dmg = k; // last hit always contributes k
            for (int i = 0; i < n - 1; i++) {
                dmg += std::min(k, v[i+1] - v[i]);
                if (dmg >= h) break; // early stop
            }

            if (dmg >= h) {
                ans = k;
                r = k - 1; // try smaller k
            } else {
                l = k + 1; // need bigger k
            }
        }

        std::cout << ans << "\n";
    }
    return 0;
}

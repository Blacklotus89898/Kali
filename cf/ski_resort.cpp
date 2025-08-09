#include <iostream>
#include <vector>

using ll = long long;

int main() {
    ll t;
    std::cin >> t;

    while (t--) {
        ll n, k, q;
        std::cin >> n >> k >> q;

        std::vector<ll> a(n);
        for (ll &x : a) {
            std::cin >> x;
        }

        ll result = 0, counter = 0;
        for (ll i = 0; i < n; ++i) {
            if (a[i] <= q) {
                counter++;
            } else {
                if (counter >= k) {
                    result += (counter - k + 1) * (counter - k + 2) / 2;
                }
                counter = 0;
            }
        }

        // process last segment if still valid
        if (counter >= k) {
            result += (counter - k + 1) * (counter - k + 2) / 2;
        }

        std::cout << result << '\n';
    }

    return 0;
}

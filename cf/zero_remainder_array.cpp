#include <iostream>
#include <vector>
#include <unordered_map>
#define ll long long

int main() {
    int t = 0;
    std::cin >> t;
    while (t--) {
        int n = 0;
        ll k = 0;
        std::cin >> n >> k;

        std::unordered_map<ll, ll> freq;
        ll max_steps = 0;

        for (int i = 0; i < n; ++i) {
            ll x = 0;
            std::cin >> x;
            ll dist = (k - x % k) % k;
            if (dist != 0) {
                freq[dist]++;
                ll steps = k * (freq[dist] - 1) + dist + 1;
                max_steps = std::max(max_steps, steps);
            }
        }

        std::cout << max_steps << std::endl;
    }

    return 0;
}

// use max on the each possible cases instead of trying to find optimal pair, just test each of them
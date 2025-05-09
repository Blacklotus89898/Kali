#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll n = 0;
    std::cin >> n;

    std::vector<ll> nums(n);
    for (ll& x : nums) std::cin >> x;

    // Prefix sum of original
    std::vector<ll> accN(n);
    accN[0] = nums[0];
    for (int i = 1; i < n; ++i) accN[i] = accN[i - 1] + nums[i];

    // Sort descending and prefix sum
    std::vector<ll> sorted = nums;
    std::sort(sorted.begin(), sorted.end());

    std::vector<ll> accNS(n);
    accNS[0] = sorted[0];
    for (int i = 1; i < n; ++i) accNS[i] = accNS[i - 1] + sorted[i];

    ll m = 0;
    std::cin >> m;
    while (m--) {
        ll t, l, r;
        std::cin >> t >> l >> r;
        l--; r--; // convert to 0-based

        if (t == 1) {
            std::cout << accN[r] - (l > 0 ? accN[l - 1] : 0) << '\n';
        } else if (t == 2) {
            std::cout << accNS[r] - (l > 0 ? accNS[l - 1] : 0) << '\n';
        } else {
            std::cerr << "Invalid query type\n";
        }
    }

    return 0;
}

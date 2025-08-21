#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    // Precompute powers of 10 up to 10^18
    vector<unsigned long long> pow10(19, 1);
    for (int i = 1; i <= 18; ++i) pow10[i] = pow10[i-1] * 10ULL;

    while (t--) {
        unsigned long long n;
        cin >> n;

        vector<unsigned long long> ans;
        for (int k = 1; k <= 18; ++k) {
            unsigned long long d = pow10[k] + 1ULL; // divisor = 10^k + 1
            if (d > n) break;
            if (n % d == 0ULL) {
                ans.push_back(n / d);
            }
        }

        if (ans.empty()) {
            cout << 0 << "\n";
        } else {
            sort(ans.begin(), ans.end());
            cout << ans.size();
            for (auto x : ans) cout << " " << x;
            cout << "\n";
        }
    }

    return 0;
}

// should have drawn out the algebra and realized that the divisors are of the form 10^k + 1
// where k is from 1 to 18, and then checked if n is divisible by those divisors
#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        vector<int> prefix(n), suffix(n);
        unordered_set<char> seen;

        // Compute prefix f(a)
        seen.clear();
        for (int i = 0; i < n; ++i) {
            seen.insert(s[i]);
            prefix[i] = seen.size();
        }

        // Compute suffix f(b)
        seen.clear();
        for (int i = n - 1; i >= 0; --i) {
            seen.insert(s[i]);
            suffix[i] = seen.size();
        }

        // Try all split points and compute max f(a) + f(b)
        int max_sum = 0;
        for (int i = 1; i < n; ++i) {
            max_sum = max(max_sum, prefix[i - 1] + suffix[i]);
        }

        cout << max_sum << '\n';
    }

    return 0;
}

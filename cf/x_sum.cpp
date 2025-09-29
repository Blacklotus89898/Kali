#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<ll>> a(n, vector<ll>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> a[i][j];

        int diagCount = n + m - 1; // number of distinct diagonals in each orientation
        vector<ll> sumBackslash(diagCount, 0); // index = i + j
        vector<ll> sumSlash(diagCount, 0);     // index = i - j + (m-1)

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                sumBackslash[i + j] += a[i][j];
                sumSlash[i - j + (m - 1)] += a[i][j];
            }
        }

        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ll total = sumBackslash[i + j] + sumSlash[i - j + (m - 1)] - a[i][j];
                ans = max(ans, total);
            }
        }

        cout << ans << '\n';
    }
    return 0;
}

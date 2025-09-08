#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> a(k+1, 0), b(k+1, 0);

        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            if (x <= k) a[x] = 1;
        }
        for (int i = 0; i < m; i++) {
            int x; cin >> x;
            if (x <= k) b[x] = 1;
        }

        int ai = 0, bi = 0, common = 0;
        for (int i = 1; i <= k; i++) {
            if (!a[i] && !b[i]) { 
                common = -1; // missing number
                break;
            }
            if (a[i] && !b[i]) ai++;
            else if (b[i] && !a[i]) bi++;
            else common++;
        }

        if (common == -1 || ai > k/2 || bi > k/2) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }

    return 0;
}

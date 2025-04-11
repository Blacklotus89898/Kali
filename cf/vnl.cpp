#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    ll l;
    cin >> n >> l;

    vector<ll> lan(n);
    for (int i = 0; i < n; ++i) {
        cin >> lan[i];
    }

    sort(lan.begin(), lan.end());

    // Max radius is the max of:
    // - distance from start to first lantern
    // - distance from end to last lantern
    // - half of the max gap between adjacent lanterns
    double radius = max((double)lan[0], (double)(l - lan[n - 1]));

    for (int i = 0; i < n - 1; ++i) {
        double gap = (lan[i + 1] - lan[i]) / 2.0;
        radius = max(radius, gap);
    }

    cout << fixed << setprecision(10) << radius << "\n";
    return 0;
}

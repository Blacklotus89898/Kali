#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

pair<ll, ll> solve(ll x, ll n, ll m) {
    ll maxValue = x, minValue = x;
    ll nMax = n, mMax = m, nMin = n, mMin = m;

    // Compute maxValue
    while (nMax > 0 || mMax > 0) {
        if (maxValue % 2 == 0 && nMax > 0) {
            maxValue /= 2;
            nMax--;
        } else if (mMax > 0) {
            maxValue = (maxValue + 1) >> 1;
            mMax--;
        } else {
            maxValue /= 2;
            nMax--;
        }
    }

    // Compute minValue
    while (nMin > 0 || mMin > 0) {
        if (minValue % 2 == 1 && nMin > 0) {
            minValue = minValue >> 1;
            nMin--;
        } else if (mMin > 0) {
            minValue /= 2;
            mMin--;
        } else {
            minValue /= 2;
            nMin--;
        }
    }

    return {minValue, maxValue};
}

int main() {
    ll l, x, n, m;
    cin >> l;
    vector<pair<ll, ll>> result(l);

    for (ll i = 0; i < l; ++i) {
        cin >> x >> n >> m;
        result[i] = solve(x, n, m);
    }

    for (const auto& p : result) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}

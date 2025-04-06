#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

ll max_hamburgers(string recipe, ll nb, ll ns, ll nc, ll pb, ll ps, ll pc, ll r) {
    // Count ingredient requirements per hamburger
    ll need_b = count(recipe.begin(), recipe.end(), 'B');
    ll need_s = count(recipe.begin(), recipe.end(), 'S');
    ll need_c = count(recipe.begin(), recipe.end(), 'C');

    // Function to check if we can make `x` hamburgers with given money
    auto can_make = [&](ll x) {
        ll req_b = max(0LL, need_b * x - nb);
        ll req_s = max(0LL, need_s * x - ns);
        ll req_c = max(0LL, need_c * x - nc);

        ll total_cost = req_b * pb + req_s * ps + req_c * pc;
        return total_cost <= r;
    };

    // Find the maximum number of hamburgers using a mathematical approach
    ll left = 0, right = r + nb + ns + nc;  // Upper bound estimate
    while (left < right) {
        ll mid = (left + right + 1) / 2;  // Avoid infinite loops
        if (can_make(mid))
            left = mid;
        else
            right = mid - 1;
    }

    return left;
}

int main() {
    string recipe;
    cin >> recipe;

    ll nb, ns, nc;
    cin >> nb >> ns >> nc;

    ll pb, ps, pc, r;
    cin >> pb >> ps >> pc >> r;

    cout << max_hamburgers(recipe, nb, ns, nc, pb, ps, pc, r) << endl;
    return 0;
}

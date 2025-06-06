#include <iostream>
#include <vector>
typedef long long ll;


int main() {

    ll n, m;
    std::cin >> n >> m;
    std::vector<ll> v(m, 0);

    for (ll i = 0; i < m; ++i) {
        std::cin >> v[i];
    }

    ll cur = 1;
    ll time = 0;
    for( const auto& val: v) {
        if (val < cur) {
            time += n - cur + val;
        } else {
            time += val - cur;
        }
        cur = val;
    }

    std::cout << time << std::endl;

    return 0;
}
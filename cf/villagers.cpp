#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
int main() {
    int t = 0;
    std::cin >> t;

    while(t--) {

        int n = 0;
        std::cin >> n;

        std::vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        sort(a.begin(), a.end(), std::greater<ll>());

        ll em = 0;
        for (int i = 0; i < n; i += 2) {
            em += a[i];
        }

        std::cout << em << '\n';


    }


    return 0;
}
#include <iostream>
#include <map>

#define ll long long

int main() {

    //make the progressive square
    int t = 0;

    std::cin >> t;

    while (t--) {
        
        ll n, c, d;

        std::cin >> n >> c >> d;

        std::map<ll, ll> m;
        std::map<ll, ll> s;

        for (int i = 0; i < n*n; ++i) {
            ll x;
            std::cin >> x;
            m[x]++;
        }

        ll smallest = m.begin()->first; //getr the starting since already sorted

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ll val = smallest + i*d + j*c;
                s[val]++;
            }
        }

        if(s == m) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }

    }



    return 0;
}
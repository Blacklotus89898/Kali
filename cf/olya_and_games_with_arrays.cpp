#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

int main() {
    ll t= 0;
    std::cin >> t;
    
    while (t--) {
        ll n = 0;
        std::cin >> n;

        std::vector<std::vector<ll>> a;
        while (n--) {
            ll m = 0;
            std::cin >> m;
            std::vector<ll> row;
            while (m--) {
                ll x = 0;
                std::cin >> x;
                row.push_back(x);
            }
            std::sort(row.begin(), row.end()); // no need to sort if we use pairs and min value
            a.push_back(row);            
        }

         
        // no need of index as we keep track of the values
        ll smallest = a[0][1];
        ll sum = smallest;
        ll mini = a[0][0];
        for (ll i = 1; i < a.size(); ++i) {
            if (a[i][1] < smallest) {
                smallest = a[i][1];
            } 
            mini = std::min(a[i][0], mini);
            sum += a[i][1];
        }

        sum -= smallest;
        sum += mini;
        std::cout << sum << std::endl;
        
    }

    return 0;
}
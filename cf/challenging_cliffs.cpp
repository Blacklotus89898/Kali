#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

int main() {
    int t = 0;
    std::cin >> t;

    while(t--) {
        ll n = 0;
        std::cin >> n;

        std::vector<ll> a(n, 0); 
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        std::sort(a.begin(), a.end());

        if (n == 2) {
            std::cout << a[0] << " " << a[1] << std::endl;
            continue;
        }

        ll start = 0;
        ll end = 1; // could be negative I guess?, compared it with the last one and failed the test...

        for (int i = 0; i < n-1; ++i) {
            if (a[i + 1] - a[i] < a[end] - a[start]) {
                start = i;
                end = i + 1;
            }
        }

        std::vector<ll> result;
        for (int i = end; i < n; ++i) {
            result.push_back(a[i]);
        }

        for (int i = 0; i <= start; ++i) {
            result.push_back(a[i]);
        }

        for (const ll& r: result) {
            std::cout << r << " ";
        }
        std::cout << std::endl;


    }


    return 0;
}
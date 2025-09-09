#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

int main() {
    int t = 0;
    
    std::cin >> t;

    while(t--) {

        ll n, m;
        std::cin >> n >> m;

        std::vector<ll> ovens(n, 0);
        for (int i = 0; i < n; ++i) {
            std::cin >> ovens[i];
        }

        std::sort(ovens.begin(), ovens.end(), std::greater());

        ll result = 0;
        for (int i = m; i > 0; --i) {
            if ((m-i) > (n-1)) {
                break;
            }
            result += ovens[m-i] * i;
            // std::cout << "val" << val;

            // std::cout << "ovens" << ovens[m-i];
            // std::cout << "i" << i;
            // std::cout << "curr" << result << std::endl;
        }

        std::cout << result << std::endl;

    }


    return 0;
}
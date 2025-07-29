#include <iostream>
#define ll long long

int main() {

    ll t = 0;
    std::cin >> t;

    while (t--)
    {
        ll a = 0, b = 0;
        std::cin >> a >> b;
        if (b == 1) { 
            std::cout << "NO" << std::endl; 
        } else {
            // b is not 1
            ll x = a * b;
            ll y = a;
            ll z = x + y;

            std::cout << "YES" << std::endl;
            std::cout << x << " " << y << " " << z << std::endl;
        }
    }
    

    return 0;
}
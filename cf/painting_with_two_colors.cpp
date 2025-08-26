#include <iostream>

#define ll long long

int main(){

    int t = 0;
    std::cin >> t;
    
    while (t--) {
        ll n, a, b;
        std::cin >> n >> a >> b;
        
        
        if ((b % 2 == n % 2 && a % 2 == b % 2) || (b >= a && b % 2 == n % 2)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}
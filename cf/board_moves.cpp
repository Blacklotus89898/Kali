#include <iostream>
#define ll long long

int main() {
    int t = 0;
    std::cin >> t;

    while (t--) {
        ll n;
        std::cin >> n;

        ll moves = 0;

        // Each layer i contributes 8 * i * i moves
        for (ll i = 1; i <= (n - 1) / 2; ++i) {
            moves += 8LL * i * i;
        }

        std::cout << moves << std::endl;
    }

    return 0;
}

#include <iostream>
#define ll long long

int main() {
// Observation: n cannot be smaller than 1 * k 
// if n is even, k should work with even b
// if n is odd then k must be odd and num are also odd
// if n is 0, k must be 0
// same parity can be reduced using 1's and remainder

int t = 0;
std::cin >> t;
while  (t--) {
    ll n = 0, k = 0;
    std::cin >> n >> k;

    if (n < k) {
        std::cout << "NO" << std::endl;
        continue;
    }

    if (n % 2 == 1) {
        if (k % 2 == 0) {
            std::cout << "NO" << std::endl;
            continue;
        } else {
            std::cout << "YES" << std::endl;
            while (k-- > 1) {
                std::cout << "1 ";
                n -= 1;
            }
            std::cout << n << std::endl;
        }

    } else {
        //even case
        if (k % 2 == 1) {
            if (n < 2 * k) {
                std::cout << "NO" << std::endl;
                continue;
            }
            std::cout << "YES" << std::endl;
            while (k-- > 1) {
                std::cout << "2 ";
                n -= 2;
            }
            std::cout << n << std::endl;
        } else {
            std::cout << "YES" << std::endl;
            while (k-- > 1) {
                std::cout << "1 ";
                n -= 1;
            }
            std::cout << n << std::endl;
        }
    } 
}


    return 0;
}

// Optimal solution:
/*
#include <iostream>
#define ll long long

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        ll n, k;
        std::cin >> n >> k;

        if ((n >= k) && (n % 2 == k % 2)) {
            std::cout << "YES\n";
            for (int i = 0; i < k - 1; ++i) {
                std::cout << 1 << " ";
            }
            std::cout << (n - (k - 1)) << "\n";
        }
        else if ((n >= 2 * k) && (n % 2 == 0)) {
            std::cout << "YES\n";
            for (int i = 0; i < k - 1; ++i) {
                std::cout << 2 << " ";
            }
            std::cout << (n - 2 * (k - 1)) << "\n";
        }
        else {
            std::cout << "NO\n";
        }
    }
    return 0;
}


*/
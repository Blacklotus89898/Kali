#include <iostream>
#include <vector>

#define ll long long

int main() {

    int t = 0;
    std::cin >> t;

    while (t--) {
        long long n = 0;
        std::cin >> n;

        std::vector<ll> a(n, 0);
        for(int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        ll moves = 0;

        
        if (n == 2) {
            if (a[0] > a[1]) {
                moves += a[0] - a[1];
                std::cout  << moves << std::endl;
                continue;
            }
        }

        for (int i = 1; i < n-1; i += 2) { // 1,2,3,4,5
            // while (a[i] - a[i - 1] - a[i+1] < 0) {
            //     if (a[i + 1] > 0) { 
            //         //reduce the shared 
            //         a[i + 1]--;
            //     } else if (a[i - 1] > 0) {
            //         a[i - 1]--;
            //     } 
            //     moves++;
            // };

            if (a[i] - a[i - 1] - a[i+1] < 0) {
                moves += -a[i] + a[i - 1] + a[i+1];
                a[i + 1] = std::max(0LL,  a[i] - a[i - 1]); 
            }
            
        }


        if (n % 2 == 0) { // even length, last one is n-1
            if (a[n - 2] > a[n - 1]) {
                moves += a[n - 2] - a[n - 1];
            }
        }

        std::cout  << moves << std::endl;
    }

    return 0;
}

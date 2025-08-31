#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

#define ll long long

int main() {
    int t = 0;
    std::cin >> t;
    
    while (t--) {
        int n = 0;
        std::cin >> n;

        std::vector<ll> arr(n, 0);
        // std::vector<ll> even;
        // std::vector<ll> odd;
        for (int i = 0; i < n; ++i) {
            // ll x = 0;
            std::cin >> arr[i];
            // std::cin >> x;
            // if (x % 2 == 0) {
            //     even.push_back(x);
            // } else {
            //     odd.push_back(x);
            // }
        }

        std::sort(arr.begin(), arr.end(), std::greater<ll>());
        // for (const auto& x : arr) {
        //     if (x % 2 == 0) {
        //         even.push_back(x);
        //     } else {
        //         odd.push_back(x);
        //     }
        // }
        // std::sort(even.begin(), even.end(), std::greater<ll>());
        // std::sort(odd.begin(), odd.end(), std::greater<ll>());

        ll alice = 0;
        ll bob = 0;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) { // Alice's turn
                if (arr[i] % 2 == 0) alice += arr[i];
            } else {          // Bob's turn
                if (arr[i] % 2 == 1) bob += arr[i];
            }
        }
        // while (!even.empty() || !odd.empty()) {
        //     // alice's turn
        //     if (!even.empty()) {
        //         if (odd.empty() || even[0] >= odd[0]) {
        //             alice += even[0];
        //             even.erase(even.begin());
        //         } else {
        //             if (!odd.empty()) {
        //                 odd.erase(odd.begin());
        //             }
        //         }
        //     } else {
        //         if (!odd.empty()) {
        //             odd.erase(odd.begin());
        //         }
        //     }

        //     // bob's turn
        //     if (!even.empty() || !odd.empty()) {
        //         if (!odd.empty()) {
        //             if (even.empty() || odd[0] >= even[0]) {
        //                 bob += odd[0];
        //                 odd.erase(odd.begin());
        //             } else {
        //                 if (!even.empty()) {
        //                     even.erase(even.begin());
        //                 }
        //             }
        //         } else {
        //             if (!even.empty()) {
        //                 even.erase(even.begin());
        //             }
        //         }
        //     }
        // }

        if (alice > bob) {
            std::cout << "Alice" << std::endl;
        } else if (bob > alice) {
            std::cout << "Bob" << std::endl;
        } else {
            std::cout << "Tie" << std::endl;
        }

        

    }



    return 0;
}
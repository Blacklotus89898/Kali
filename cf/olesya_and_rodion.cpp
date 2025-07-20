#include <iostream>
#include <cmath>
#include <string>

// Just construct a valid answer directly
int main() {
    int n, t;
    std::cin >> n >> t;

    std::string result;

    if (t == 10) {
        if (n == 1) {
            std::cout << -1 << std::endl;
        } else {
            result = "1" + std::string(n - 1, '0'); // e.g. 1000
            std::cout << result << std::endl;
        }
    } else {
        result = std::string(1, '0' + t) + std::string(n - 1, '0'); // e.g. 2000 for t=2
        std::cout << result << std::endl;
    }

    return 0;
}




// TOO slow
// int main() {
//     int n, t;
//     std::cin >> n >> t; // n digit, div by t
//     ll higher = pow(10, n ) - 1; // largest n-digit number
//     ll lower = pow(10, n - 1); // lower n-digit number
//     ll curr = t;
    
//     while (curr < lower) {
//         curr += t; // increment by t until we reach or exceed lower
//     }

//     t > higher ? std::cout << -1 : std::cout << curr;

//     return 0;
// }
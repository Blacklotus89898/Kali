#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        ll sum = 0, curr = 0;
        bool positive = true; // Tracks the current sign of the segment

        for (int i = 0; i < n; ++i) {
            ll x;
            std::cin >> x;

            if ((x > 0 && positive) || (x < 0 && !positive)) {
                curr = std::max(curr, x); // Extend the current segment
            } else {
                sum += curr;             // Add the previous segment to the sum
                curr = x;                // Start a new segment
                positive = (x > 0);      // Update the sign tracker
            }
        }

        sum += curr; // Add the last segment
        std::cout << sum << std::endl;
    }

    return 0;
}

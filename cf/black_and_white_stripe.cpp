#include <iostream>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, k;
        std::cin >> n >> k;

        std::string s;
        std::cin >> s;

        int curr = 0;
        // Count 'W's in the first window
        for (int i = 0; i < k; ++i) {
            if (s[i] == 'W') {
                curr++;
            }
        }

        int min_w = curr; // Minimum 'W's in any window of size k

        for (int i = 1; i <= n - k; ++i) {
            if (s[i - 1] == 'W') curr--;         // remove left element
            if (s[i + k - 1] == 'W') curr++;     // add right element
            min_w = std::min(min_w, curr);       // track minimum
        }

        std::cout << min_w << std::endl;
    }

    return 0;
}

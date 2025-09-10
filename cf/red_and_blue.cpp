#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t = 0;
    std::cin >> t;

    while (t--) {
        size_t n, m;
        std::cin >> n;

        // Validate input sizes to prevent excessive memory allocation
        std::vector<int> r(n);
        
        for (size_t i = 0; i < n; ++i) {
            std::cin >> r[i];
        }
        
        std::cin >> m;
        std::vector<int> b(m);
        
        for (size_t i = 0; i < m; ++i) {
            std::cin >> b[i];
        }

        int maxPrefixR = 0, maxPrefixB = 0;
        int currSum = 0;

        // Compute max prefix sum for r[]
        for (size_t i = 0; i < n; ++i) {
            currSum += r[i];
            maxPrefixR = std::max(maxPrefixR, currSum);
        }

        currSum = 0; // Reset before processing b[]

        // Compute max prefix sum for b[]
        for (size_t i = 0; i < m; ++i) {
            currSum += b[i];
            maxPrefixB = std::max(maxPrefixB, currSum);
        }

        int result = maxPrefixR + maxPrefixB;
        std::cout << result << std::endl;
    }

    return 0;
}
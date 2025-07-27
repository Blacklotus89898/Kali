#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t = 0;
    std::cin >> t;
    while (t--) {
        int n = 0;
        std::cin >> n;

        std::vector<int> v(n);
        int max_val = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> v[i];
            max_val = std::max(max_val, v[i]);
        }

        int result = 0;

        // Iterate over possible sums, use a frequency array to count occurrences, and find the complement pair
        for (int sum = 2; sum <= 2 * max_val; ++sum) {
            std::vector<int> freq(max_val + 1, 0);
            for (int x : v) {
                freq[x]++;
            }

            int current = 0;
            for (int x = 1; x <= sum / 2; ++x) {
                int y = sum - x;
                if (y > max_val) continue;
                if (x == y) {
                    current += freq[x] / 2;
                } else {
                    current += std::min(freq[x], freq[y]);
                }
            }
            result = std::max(result, current);
        }

        std::cout << result << std::endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n;
    std::cin >> n;

    std::unordered_map<int, int> freq;
    int maxFreq = 0;

    for (int i = 0; i < n; ++i) {
        int h, m;
        std::cin >> h >> m;
        int time = 100 * h + m;
        maxFreq = std::max(maxFreq, ++freq[time]);
    }

    std::cout << maxFreq << std::endl;
    return 0;
}
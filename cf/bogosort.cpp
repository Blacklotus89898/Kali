#include <iostream>
#include <algorithm>
#include <vector>


int main() {
    int t = 0;
    std::cin >> t;

    while (t--) {
        int n = 0;
        std::cin >> n;

        std::vector<int> result(n, 0);
        for (int i = 0; i < n; ++i) {
            std::cin >> result[i];
        }

        std::sort(result.begin(), result.end(), std::greater<int>());


        for (const int& r : result) {
            std::cout << r << " ";
        }

        std::cout << std::endl;

    }


    return 0;
}
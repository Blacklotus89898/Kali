#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    int t = 0;
    std::cin >> t;

    while (t--) {
        int n = 0;
        std::cin >> n;

        int len =( n* (n - 1)) / 2;
        std::vector<int> a(len);

        for (int i = 0; i < len; ++i) {
            std::cin >> a[i];
        }

        std::sort(a.begin(), a.end()); // use a sort or do a set 

        std::vector<int> result;

 
        // 111223
        int dist = 0; // jump by n-i, 
 
        for (int i = 0; dist < len; ++i) {
            result.push_back(a[dist]);
            dist += n - 1 - i;
        }

        while (result.size() < n) {
            result.push_back(a[len - 1]); // fill with greater than max
        }

        for (int i = 0; i < result.size(); ++i) {
            std::cout << result[i] << " ";
        }

        std::cout << std::endl;





    }
    

    return 0;
}

/*

map to store the frequency



start with most frequent then compare if decrease to

*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>

int main()
{
    int t = 0;

    std::cin >> t;
    while (t--)
    {
        int n = 0;

        std::cin >> n;
        std::unordered_map<int, int> m;

        for (int i = 0; i < n; ++i) {
            int x = 0;
            std::cin >> x;
            m[x]++;
        }

        int res = 0;
        for(int i = 100; i > 0; --i) {
            int counter = 0;
            for (const auto& p: m) {
                if (p.second >= i) {
                    counter++;
                }

            }
            res = std::max(res, counter*i);
        }

        std::cout << res << std::endl;
 
    }

    return 0;
}

//sdfgdsfkjgdfskjghsdflkjghdfskljgklfds
// brute fgosd fghi dsfkjgdshflkgjdfs

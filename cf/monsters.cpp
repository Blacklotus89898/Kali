#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

// cursed editorial -- incomplete
int main()
{
    int t = 0;
    std::cin >> t;

    while (t--)
    {
        int n = 0;
        int k = 0;
        std::cin >> n >> k;

        std::unordered_map<int, std::vector<int>> m;
        std::set<int, std::greater<int>> s; // keeps numbers sorted descending

        for (int i = 0; i < n; ++i)
        {
            int x = 0;
            std::cin >> x;
            m[x].push_back(i);
            s.insert(x);
        }

        while (s.size() > 1)
        {
            int large = *s.begin(); 
            s.erase(large);

            // merge indices from "large" into its reduced value
            int reduced = std::max(0, large - k);

            if (m.find(large) != m.end()) {
                m[reduced].insert(m[reduced].end(), m[large].begin(), m[large].end());
                m.erase(large);
            }

            s.insert(reduced);
        }

        // final remaining bucket
        int finalKey = *s.begin();
        auto &vec = m[finalKey];

        std::vector<int> result(n, 0);
        for (int i = 0; i < n; i++)
        {
            result[vec[i]] = i + 1;
        }

        for (int r : result)
        {
            std::cout << r << " ";
        }
        std::cout << "\n";
    }

    return 0;
}

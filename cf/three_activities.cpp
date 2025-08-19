#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

int main()
{

    int t = 0;
    std::cin >> t;

    while (t--)
    {

        
        int n = 0;

        std::cin >> n;

        std::vector<std::pair<int, int>> a;
        std::vector<std::pair<int, int>> b;
        std::vector<std::pair<int, int>> c;

        for (int i = 0; i < n; ++i)
        {
            int x = 0;
            std::cin >> x;
            a.insert(a.end(), std::make_pair(x, i));
        }
        for (int i = 0; i < n; ++i)
        {
            int x = 0;
            std::cin >> x;
            b.insert(b.end(), std::make_pair(x, i));
        }
        for (int i = 0; i < n; ++i)
        {
            int x = 0;
            std::cin >> x;
            c.insert(c.end(), std::make_pair(x, i));
        }

        std::sort(a.begin(), a.end(), [](const std::pair<int, int> &x, const std::pair<int, int> &y)
                  { return x.first > y.first; });
        std::sort(b.begin(), b.end(), [](const std::pair<int, int> &x, const std::pair<int, int> &y)
                  { return x.first > y.first; });
        std::sort(c.begin(), c.end(), [](const std::pair<int, int> &x, const std::pair<int, int> &y)
                  { return x.first > y.first; });

        int result = 0;

        // result = std::max({
        //     a[0].first + b[1].first + c[2].first,
        //     a[0].first + b[2].first + c[1].first,
        //     a[1].first + b[0].first + c[2].first,
        //     a[2].first + b[0].first + c[1].first,
        //     a[1].first + b[2].first + c[0].first,
        //     a[2].first + b[1].first + c[0].first
        // });

        // or use

        for (int i = 0; i < std::min(3, (int)a.size()); ++i)
        {
            for (int j = 0; j < std::min(3, (int)b.size()); ++j)
            {
                for (int k = 0; k < std::min(3, (int)c.size()); ++k)
                {
                    if (a[i].second != b[j].second && b[j].second != c[k].second && a[i].second != c[k].second)
                    {
                        result = std::max(result, a[i].first + b[j].first + c[k].first);
                    }
                }
            }
        }

        std::cout << result << std::endl;
    }

    return 0;
}
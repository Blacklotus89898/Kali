#include <iostream>
#include <unordered_map>
#include <vector>
 
#define ll long long
 
int main()
{
    int t = 0;
    std::cin >> t;
    while (t--)
    {
 
        int n = 0;
        std::cin >> n;
 
        std::vector<ll> v;
        std::unordered_map<ll, int> m;
        std::vector<int> res;
 
        for (int i = 0; i < n; ++i)
        {
            ll x = 0;
            std::cin >> x;
            v.push_back(x);
            m[x]++;
            res.push_back(i + 1);
        }
 
        bool invalid = false;
        for (const auto& p: m)
        {
            if (p.second == 1)
            {
                invalid = true;
                break;
            }
        }
 
        if (invalid)
        {
            std::cout << -1 << std::endl;
        }
        else
        {
            for (int i = 0; i < n - 1; ++i)
            {
                if (v[i] == v[i + 1])
                {
                    std::swap(res[i], res[i + 1]);
                }
            }
 
            for (int i = 0; i < n; ++i)
            {
                std::cout << res[i] << " ";
            }
 
            std::cout << std::endl;
        }
    }
}
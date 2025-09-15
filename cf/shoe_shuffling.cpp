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
        // std::unordered_map<ll, int> m;
        std::vector<int> res;
        
        ll last = -1;
        ll counter = 0;
        
        bool invalid = false;
        for (int i = 0; i < n; ++i)
        {
            ll x = 0;
            std::cin >> x;
            
            if (last != x) {
                if (counter == 1) {
                    invalid = true;
                    break;// will cause input desync
                }
                counter = 0;
            }

            v.push_back(x);
            last = x;
            counter++;

        
            // m[x]++;


            res.push_back(i + 1);
        }

 
        // for (const auto& p: m)
        // {
        //     if (p.second == 1)
        //     {
        //         invalid = true;
        //         break;
        //     }
        // }
 
        if (invalid || counter == 1)
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
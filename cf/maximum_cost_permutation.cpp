#include <iostream>
#include <vector>
#include <set>

int main()
{
    // check element not in order
    // no 0 case == easy
    // two or more zero case == get the max between not in order number and 0's and between the 0's
    // 0 look for not in order int and compute the difference

    int t = 0;
    std::cin >> t;
    while (t--)
    {

        int n = 0;
        std::cin >> n;
        std::vector<int> v(n, 0);
        std::vector<int> s(n, 0);

        for(int i = 0; i < n; ++i) {
            s[i] = 1;
        }


        int target = 0;

        int zeros = 0;
        for (int i = 0; i < n; ++i)
        {
            std::cin >> v[i];
            if (v[i] == 0) {
                zeros++;
                target = i;

            } else {
                s[v[i]-1] = 0;
            }
        }

        int l = 0;
        int r = n - 1;
        bool ls = false;
        bool rs = false;

        if (zeros == 1) {
            for (int i = 0; i < n; ++i) {
                if(s[i] == 1) {
                    v[target] = i+1;
                }
            }
        }

        while ((!ls || !rs) && l < r) {
            if(v[r] == 0 || v[r] != r+1) {
                rs = true;
            } else {
                r--;
            }
            if (v[l] == 0 || v[l] != l+1) {
                ls = true;
            } else {
                l++;
            }
        }
        
        if (l < r) {
        std::cout << r - l + 1 << std::endl; 
        } else {
            std::cout << 0 << std::endl; 
        }
    }
}
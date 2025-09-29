#include <iostream>

int main()
{

    int t = 0;
    std::cin >> t;
    while (t--)
    {

        int res = 0;

        // technically, al + b, is max when l is 1
        // if a is negative, depends on B, if b is negative,
        int n, a, b;
        std::cin >> n >> a >> b;
        std::string s;
        std::cin >> s;

        char curr = s[0];
        int seg = 1;
        for (const char &c : s)
        {
            if (c != curr)
            {
                seg++;
                curr = c;
            }
        }

        if (b > 0)
        {
            res = a * s.size() + b * s.size();
        }
        else
        {
                res = a * s.size() + b * (seg/2 + 1);
                
        }

        std::cout << res << std::endl;
    }

    return 0;
}

// 000, 00 111, 000111000, 000110001110011110000

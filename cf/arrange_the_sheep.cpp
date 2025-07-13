#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint> 

int main()
{
    int t = 0;
    std::cin >> t;

    while (t--)
    {
        int n = 0;
        std::cin >> n;

        std::string s;
        std::cin >> s;

        std::vector<int64_t> sheeps;
        for (int64_t i = 0; i < s.size(); ++i)
        {
            if (s[i] == '*')
            {
                sheeps.push_back(i);
            }
        }

        if (sheeps.size() <= 1)
        {
            std::cout << 0 << std::endl;
            continue;
        }

        int64_t median_index = sheeps.size() / 2;
        int64_t median_sheep = sheeps[median_index];
        int64_t move = 0;

        for (int64_t i = 0; i < sheeps.size(); ++i)
        {
            move += std::abs(sheeps[i] - median_sheep) - std::abs(i - median_index);
        }

        std::cout << move << std::endl;
    }

    return 0;
}

#include <iostream>
#define ll long long

int main()
{
    int t = 0;
    std::cin >> t;

    while (t--)
    {
        int n = 0;
        std::cin >> n;

        ll sum = 0;
        ll maxVal = 0;
        int counter = 0;
        ll cur = 0;

        for (int i = 0; i < n; ++i)
        {
            std::cin >> cur;
            sum += cur;
            maxVal = std::max(maxVal, cur);
            if (maxVal * 2 == sum)
            {
                counter++;
            }
        }

        std::cout << counter << std::endl;
    }

    return 0;
}
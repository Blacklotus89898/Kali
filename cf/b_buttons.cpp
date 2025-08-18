#include <iostream>

int main()
{

    int n = 0;
    std::cin >> n;

    // if (n == 1)
    // {
    //     std::cout << 1 << std::endl;
    // }
    // else if (n <= 2)
    // {
    //     std::cout << 3 << std::endl;
    // }
    // else
    {
        int result = n;

        int layer = 1;
        for (int i = n; i > 0; --i)
        {
            if (i != 1) {
                result += (i-1) * layer;
            } 
            layer++;
        }

        std::cout << result << std::endl; //total button press ... oups
    }

    return 0;
}

// 2 * 1 + 1 * 2 + 3

// 1 * 1 + 2

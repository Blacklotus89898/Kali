#include <iostream>

int main()
{
    int t = 0;
    std::cin >> t;

    while (t--)
    {
        int n = 0;
        char cur = ' ';

        std::cin >> n >> cur;

        std::string lights = "";
        std::cin >> lights;

        int result = 0; // max value

        if (cur == 'g')
        {
            std::cout << result << std::endl;
            continue;
        }
        else
        {
            for (int i = 0; i < n; ++i)
            {
                if (lights[i] == cur)
                {
                    // find next g
                    int counter = 0;
                    int j = i;
                    while (lights[j] != 'g')
                    {
                        j++;
                        if (j == n)
                        {
                            j = 0; // wrap around
                        }
                        counter++;
                    }

                    result = std::max(result, counter);
                    if (j > i)
                    {
                        i = j - 1; // skip to the next light after g
                    }
                    else
                    {
                        break;
                    }
                }
            }

            std::cout << result << std::endl; // max distance to next g
        }
    }

    return 0;
}
#include <iostream>
#include <vector>

int main()
{

    int t = 0;
    std::cin >> t;

    while (t--)
    {
        int n = 0;
        std::cin >> n;

        if (n == 1)
        {
            std::cout << 1 << std::endl;
        }
        else if (n == 2)
        {
            std::cout << -1 << std::endl;
        }
        else
        {
            std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
            for (int i = 0; i < n * n; ++i)
            {
                matrix[i % n][(i + i / n) % n] = i + 1; //diagonal fill, 
            }

            for (const auto &row : matrix) 
            {
                for (int j = 0; j < row.size(); ++j)
                {
                    std::cout << row[j];
                    if (j < row.size() - 1)
                    {
                        std::cout << " ";
                    }
                }
                std::cout << std::endl;
            }
        }
    }

    return 0;
}

// could do a stupid dp as well
// or just fill diagonally, i.e. (i, (i + i/n) % n) = i + 1
// or fill in checkerboard pattern with odd and even numbers
#include <iostream>

int main()
{
    std::string a = "";
    std::string b = "";
    std::cin >> a >> b;
    if (a == b)
    {
        std::cout << "-1" << std::endl;
    }
    else
    {
        std::cout << std::max(a.size(), b.size()) << std::endl;
    }

    return 0;
}
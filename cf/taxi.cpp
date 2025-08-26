#include <iostream>
#include <unordered_map>

int main()
{
    int n = 0;
    std::cin >> n;

    std::unordered_map<int, int> groups;
    for (int i = 0; i < n; ++i)
    {
        int x = 0;
        std::cin >> x;
        groups[x]++;
    }

    int taxis = 0;
    taxis += groups[4]; // each 4-group needs a taxi
    taxis += groups[3]; // each 3-group needs a taxi
    taxis += (groups[2] / 2); // each pair of 2-groups needs a taxi

    int singles = std::max(0, groups[1] - groups[3]); 
    
    if (groups[2] % 2 == 1) {
        singles = std::max(0, singles - 2); // one 2-group may take up to two singles
        taxis++;
    }
    taxis += (singles + 3) / 4; // each taxi can take up to four singles

    std::cout << taxis << std::endl;

    return 0;
}

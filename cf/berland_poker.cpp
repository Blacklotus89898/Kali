#include <iostream>

int main() {
    int t = 0;
    std::cin >> t;

    while (t--) {
        int n = 0;
        int m, k;
        std::cin >> n >> m >> k;

        int hand = n / k;
        int winner = std::min(m, hand);


        int rest = m - winner;
        int dist = (rest + k-2)/(k-1);

        std::cout << winner - dist << std::endl;

    }



    return 0;
}
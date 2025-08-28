#include <iostream>
#include <deque>

int main() {


    int n = 0;
    std::cin >> n;

    std::deque<std::deque<int>> d;

    for (int k = n; k >= 0; --k) {
        std::deque<int> row;
        for (int i = k; i >= 0; --i) {            
            if (i != k) {
                row.push_front(i);
            } 
            row.push_back(i);
        }

        int pad = n - row.size()/2;
        for(int i = 0; i < pad; ++i) { //only need to pad front
            row.push_front(-1);
        }

        if (k != n) {
            d.push_back(row);
        }
        d.push_front(row);
    }

    for (const auto& row: d) {
        for (const int& x: row) {
            if (x == -1) {
                std::cout << "  ";
            } else {
                std::cout << x << " ";
            }
        }
        std::cout << std::endl;
    }


    return 0;
}
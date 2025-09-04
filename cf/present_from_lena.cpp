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
        for (auto it = row.begin(); it != row.end(); ++it) {
            if (*it == -1) {
                std::cout << " ";
            } else {
                std::cout << *it;
            }
            if (std::next(it) != row.end()) { // Add space except for the last element
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }


    return 0;
}
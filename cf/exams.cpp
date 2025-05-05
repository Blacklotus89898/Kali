#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    int n = 0;
    std::cin >> n;

    std::vector<std::pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
        int a = 0, b = 0;
        std::cin >> a >> b;
        v.push_back(std::make_pair(a, b));
        
    }
    
    // sort by the first element of the pair -- need to watch out edge case
    std::sort(v.begin(), v.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return (a.first < b.first) || (a.first == b.first && a.second < b.second);
    });
    

    int prev = v[0].second;
    for (const auto& p : v) {
        if (p.second < prev) {
            prev = p.first;
        } else {
            prev = p.second;
        }
    }

    std::cout << prev << std::endl;

}

// Compile for debugging
// g++ -std=c++17 -Wall -Wextra -g -o exams exams.cpp 
// gdb ./exams
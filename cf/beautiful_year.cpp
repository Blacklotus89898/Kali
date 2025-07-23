#include <iostream>
#include <vector>
#include <set>
#include <string>

int main() {
    int y = 0;
    std::cin >> y;

    while (true) {
        y++;
        std::string s = std::to_string(y);
        if (std::set<char>(s.begin(), s.end()).size() == s.size()) {
            std::cout << y << std::endl; // all digits are unique
            break;
        }
        
    }
    return 0;
}
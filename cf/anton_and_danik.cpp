#include <iostream>

int main() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    int anton = 0, danik = 0;
    for (const char& c : s) {
        if (c == 'A') {
            anton++;
        } else if (c == 'D') {
            danik++;
        }
    }

    if (anton > danik) {
        std::cout << "Anton" << std::endl;
    } else if (anton < danik) {
        std::cout << "Danik" << std::endl;
    } else {
        std::cout << "Friendship" << std::endl;
    }

    return 0;
}
#include <iostream>


int main() {
    std::string t = "", s = "";
    std::cin >> t >> s;
    
    int n = t.size();
    if (n != s.size()) {
        std::cout << "NO" << std::endl;
        return 0;
    }
    for(int i = 0; i < n; ++i) {
        if (t[i] != s[n - 1 - i]) {
            std::cout << "NO" << std::endl;
            return 0;
        }
    }

    std::cout << "YES" << std::endl;

    return 0;
}
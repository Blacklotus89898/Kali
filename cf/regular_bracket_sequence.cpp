#include <iostream>

int main() {
    int t = 0;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;

        int stars = 0;
        int l = 0;
        bool invalid = false;
        for(const char& c: s) {
                if (c == '?') {
                    stars++;
                } else if (c == '(') {
                    l++;
                } else {
                    if (l == 0 && stars == 0) {
                        invalid = true;
                        break;
                    } 
                    if (l > 0) {
                        l--;
                    } else {
                        stars--;
                    }
                }
        }

        stars -= l;
        if (stars % 2 == 0 && !invalid && s[s.size()-1] != '(') {
            std::cout << "YES" << std::endl;
        } else {    
            std::cout << "NO" << std::endl;
        }


    }


    return 0;
}
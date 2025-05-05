#include <iostream>
// #include <string>

int main() {
    int n = 0;
    std::string s = "";
    
    std::cin >> n;
    std::cin >> s;

    int len = s.length();

    int res = 0;
    for (int i = 0; i < len-1; ++i) {
        if (s[i] == s[i+1]) {
            res++;
        }    
    }

    std::cout << res << std::endl;
    
    return 0;
}
#include <iostream>
#include <string>

int main() {

    std::string s = "";
    std::cin >> s;

    std::string rs = "";

    for (const char& c: s) {
        rs = c + rs;
    }

    std::cout << s + rs << std::endl;

    return 0;
}
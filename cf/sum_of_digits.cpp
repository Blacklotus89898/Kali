#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    int sum = 0;
    int res = 0;
    for(char c : s) {
        sum += c - '0'; // Convert char to digit
    }

    if (s.size() > 1) {
        res++;
    }

    while(sum > 9) { // Only need to reduce until single digit
        int acc = 0;
        while(sum > 0) {
            acc += sum % 10;
            sum /= 10;
        }
        sum = acc;
        res++;
    }

    std::cout << res << std::endl;
    return 0;
}
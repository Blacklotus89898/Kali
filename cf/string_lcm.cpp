#include <iostream>
#include <string>
#include <numeric>  // for lcm in C++17 or later

std::string repeat_to_length(const std::string& s, int length) {
    std::string result;
    while (result.size() < length) {
        result += s;
    }
    return result;
}

int main() {
    int q;
    std::cin >> q;

    while (q--) {
        std::string a, b;
        std::cin >> a >> b;

        int len_a = a.size();
        int len_b = b.size();
        int lcm_len = std::lcm(len_a, len_b);  // C++17

        std::string repeated_a = repeat_to_length(a, lcm_len);
        std::string repeated_b = repeat_to_length(b, lcm_len);

        if (repeated_a == repeated_b) {
            std::cout << repeated_a << '\n';
        } else {
            std::cout << -1 << '\n';
        }
    }

    return 0;
}

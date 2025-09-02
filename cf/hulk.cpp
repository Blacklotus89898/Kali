#include <iostream>

int main() {

    int n = 0;
    std::cin >> n;

    std::string result = "I hate ";
    if (n > 1) result += "that ";
    for (int i = 2; i <= n; ++i) {

        if (i % 2 == 0) {
            result += "I love ";
        } else {
            result += "I hate ";
        }

        if (i != n) {
            result += "that ";
        }
    }

    result += "it";


    std::cout << result << std::endl;

    return 0;
}
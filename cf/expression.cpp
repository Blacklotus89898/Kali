#include <iostream>
#include <algorithm>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    int result = std::max({
        a + b + c,
        a * b * c,
        a * (b + c),
        (a + b) * c,
        a + (b * c),
        (a * b) + c
    });

    std::cout << result << std::endl;
    return 0;
}

#include <iostream>

int main() {   

    int t = 0;
    std::cin >> t;

    // use only 9 and 8
    while (t--) {
        int n = 0;
        std::cin >> n;

        std::string result = "";
        if (n == 1) {
            result = "-1";
        } else {
            for (int i = 1; i < n; ++i) {
                result += "9";
            }
            result = "8" + result;
        }

        std::cout << result << std::endl;
    }


    return 0;
}
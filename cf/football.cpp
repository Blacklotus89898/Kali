#include <iostream>
#include <unordered_map>

int main() {
    int n;
    std::cin >> n;

    std::unordered_map<std::string, int> name_count;
    std::string winner;
    int current_max = 0;

    while (n--) {
        std::string name;
        std::cin >> name;
        int count = ++name_count[name];
        if (count > current_max) {
            current_max = count;
            winner = name;
        }
    }

    std::cout << winner << std::endl;

    return 0;
}

#include <iostream>
#include <unordered_map>

int main() {
    int n = 0;
    std::cin >> n;

    std::unordered_map<std::string, int> name_count;
    while (n--) {
        std::string name = "";
        std::cin >> name;
        name_count[name]++;
    }

    int current_max = 0;
    std::string winner = "";
    for (const auto& entry : name_count) {
        if (entry.second > current_max) {
            current_max = entry.second;
            winner = entry.first;
        }
    }

    std::cout << winner << std::endl;


    return 0;
}
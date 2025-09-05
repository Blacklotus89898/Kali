#include <iostream>
#include <unordered_map>
#include <utility>

int main() {

    int k = 0;
    std::cin >> k;


    std::string input;
    std::cin >> input;

    std::unordered_map<char, int> m;
    for (int i = 0; i < input.size(); ++i) {
        m[input[i]]++;
    }

    std::string seg = "";
    for (const std::pair<char, int>& p : m) {
        
        if (p.second % k != 0) {
            std::cout << "-1"<< std::endl;
            return 0;
        }
        for (int i = 0; i < p.second / k; ++i) {
            seg += p.first; 
        }
    }
    
    std::string result = "";
    for (int i = 0; i < k; ++i) {
        result += seg;
    }

    std::cout << result << std::endl;

    return 0;
}
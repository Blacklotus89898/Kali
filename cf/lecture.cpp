#include <iostream>
#include <unordered_map>


using namespace std;
int main() {
    int n = 0, m = 0;
    std::cin >> n >> m;

    unordered_map<string, string> dict;

    for(int i = 0; i < m; ++i) {
        string a, b;
        std::cin >> a >> b;
        if (a.size() <= b.size()) {
            dict[a] = a;
        } else {
            dict[a] = b;
        }
    }

    string result = "";
    for (int i = 0; i < n; ++i) {
        string word;
        std::cin >> word;
        if (dict.find(word) != dict.end()) {
            result += dict[word] + " ";
        } else {
            result += word + " ";
        }
    }

    // Remove the trailing space
    if (!result.empty()) {
        result.pop_back();
    }

    std::cout << result << std::endl;

    return 0;
}
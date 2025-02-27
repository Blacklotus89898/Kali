#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    vector<std::string> words;
    string input;
    
    getline(std::cin, input);
    istringstream iss(input);
    string word;
    
    while (iss >> word) {
        words.push_back(word);
    }
    
    // Print the words to verify
    for (const auto& w : words) {
        cout << w << endl;
    }
    
    return 0;
}
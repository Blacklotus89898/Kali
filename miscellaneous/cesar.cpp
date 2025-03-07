#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> cypher(vector<string>& words, int shift) {
    vector<string> cyphered;
    for (const auto& word : words) {
        string cyphered_word = "";
        for (const auto& c : word) {
            cyphered_word += (char)((c - 'a' + shift) % 26 + 'a');
        }
        cyphered.push_back(cyphered_word);
    }
    return cyphered;
}

vector<string> decypher(vector<string>& words, int shift) {
    vector<string> decyphered;
    for (const auto& word : words) {
        string decyphered_word = "";
        for (const auto& c : word) {
            decyphered_word += (char)((c - 'a' - shift + 26) % 26 + 'a');
        }
        decyphered.push_back(decyphered_word);
    }
    return decyphered;
}


int main() {
    vector<std::string> words;
    string input;
    
    getline(std::cin, input);
    istringstream iss(input);
    string word;
    
    while (iss >> word) {
        words.push_back(word);
    }

    vector<string> encrypted = cypher(words, 3);
    vector<string> decrypted = decypher(encrypted, 3);
    
    // Print the words to verify
    for (const auto& w : words) {
        cout << w << endl;
    }

    for (const auto& w : encrypted) {
        cout << w << endl;
    }

    for (const auto& w : decrypted) {
        cout << w << endl;
    }
    
    return 0;
}
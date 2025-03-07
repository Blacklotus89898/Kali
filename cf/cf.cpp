#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define per(i, a, b) for (int i = b - 1; i >= a; --i)

const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;

void solve() {
    // Your solution code goes here
}

void parse(vector<string>& words, int n) {  // Add `n` to specify number of lines
    string line;
    
    for (int i = 0; i < n; ++i) {  // Read `n` lines
        getline(cin, line);
        istringstream iss(line);
        string word;
        
        while (iss >> word) {  // Extract words from the line
            words.push_back(word);
        }
    }
}

int main() {
    int n;
    cin >> n;  // Input the total number of lines
    cin.ignore();  // Ignore the newline character left in the buffer

    vector<string> words;
    parse(words, n);

    // Testing the output
    for (const auto& word : words) {
        cout << word << endl;
    }

    return 0;
}

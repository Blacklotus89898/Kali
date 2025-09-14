#include <iostream>
#include <string>
#include <set>
#include <cctype>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    set<char> letters;
    for (char c : s) {
        letters.insert(tolower(c));  // normalize to lowercase
    }

    if ((int)letters.size() == 26)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}

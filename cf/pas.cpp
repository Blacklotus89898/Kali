#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    // Convert both strings to lowercase for case-insensitive comparison
    for (char &c : s1) c = tolower(c);  // Convert s1 to lowercase
    for (char &c : s2) c = tolower(c);  // Convert s2 to lowercase

    // Compare the lengths of the strings first
    if (s1.size() > s2.size()) {
        cout << "1" << endl;
        return 0;
    } else if (s1.size() < s2.size()) {
        cout << "-1" << endl;
        return 0;
    }

    // Compare the strings lexicographically character by character
    for (int i = 0; i < s1.size(); ++i) {
        if (s1[i] < s2[i]) {
            cout << "-1" << endl;
            return 0;
        } else if (s1[i] > s2[i]) {
            cout << "1" << endl;
            return 0;
        }
    }

    // If both strings are equal
    cout << "0" << endl;

    return 0;
}


#include <iostream>
// #include <string>
#include <algorithm>

using namespace std;

int main() {
    int t;
    int n;
    cin >> n >> t;

    string s;
    cin >> s;

    for (int i = 0; i < t; i++) {
        // Simulate the queue for t seconds
        for (int j = 0; j < n - 1; j++) {
            if (s[j] == 'B' && s[j + 1] == 'G') {
                swap(s[j], s[j + 1]);
                j++;  // Skip the next position
            }
        }
    }

    cout << s << endl;

    return 0;
}
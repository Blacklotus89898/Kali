#include <iostream>
#include <vector>
#include <cmath>

// using string is too costy, use arrays
using namespace std;

int main() {
    int m, s;
    cin >> m >> s;

    if (s > m * 9 || (s == 0 && m > 1)) {
        cout << "-1 -1" << endl;
        return 0;
    }

    vector<int> min_num(m, 0), max_num(m, 0);
    int remaining_s = s;

    // One-pass loop
    for (int i = 0; i < m; ++i) {
        // Fill max number from left (biggest digits first)
        int max_digit = min(9, remaining_s);
        max_num[i] = max_digit;
        remaining_s -= max_digit;
    }

    remaining_s = s - 1; // Reserve 1 to ensure first digit isn't zero
    min_num[0] = 1;

    for (int i = m - 1; i >= 0; --i) {
        int min_digit = min(9, remaining_s);
        min_num[i] += min_digit;
        remaining_s -= min_digit;
    }

    // Convert arrays to integer values
    int min_val = 0, max_val = 0;
    for (int i = 0; i < m; ++i) {
        min_val = min_val * 10 + min_num[i];
        max_val = max_val * 10 + max_num[i];
    }

    cout << min_val << " " << max_val << endl;
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, s;
    cin >> m >> s;

    // Impossible case
    if (s > m * 9 || (s == 0 && m > 1)) {
        cout << "-1 -1" << endl;
        return 0;
    }

    int max_s = s, min_s = s;

    // ---- Build MAX number ----
    vector<int> max_digits(m, 0);
    for (int i = 0; i < m; ++i) {
        int digit = min(9, max_s);
        max_digits[i] = digit;
        max_s -= digit;
    }

    // ---- Build MIN number ----
    vector<int> min_digits(m, 0);
    min_s--;  // Reserve 1 for the most significant digit
    for (int i = m - 1; i > 0; --i) {
        int digit = min(9, min_s);
        min_digits[i] = digit;
        min_s -= digit;
    }
    min_digits[0] = min_s + 1;  // Add back the reserved 1

    // Output
    for (int d : min_digits) cout << d;
    cout << " ";
    for (int d : max_digits) cout << d;
    cout << endl;

    return 0;
}

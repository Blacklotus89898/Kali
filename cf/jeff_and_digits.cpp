#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, digit;
    cin >> n;

    int count_0 = 0, count_5 = 0;
    for (int i = 0; i < n; ++i) {
        cin >> digit;
        if (digit == 0) count_0++;
        else if (digit == 5) count_5++;
    }

    if (count_0 == 0) {
        // No zero means we can't end the number with 0 → not divisible by 10
        cout << -1 << endl;
    } else if (count_5 < 9) {
        // Not enough 5s to make sum divisible by 9 → only valid number is 0
        cout << 0 << endl;
    } else {
        // Use the largest multiple of 9 less than or equal to count_5
        int usable_fives = count_5 - (count_5 % 9);
        for (int i = 0; i < usable_fives; ++i) cout << 5;
        for (int i = 0; i < count_0; ++i) cout << 0;
        cout << endl;
    }

    return 0;
}
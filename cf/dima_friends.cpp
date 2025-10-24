#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int sum_friends = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        sum_friends += x;
    }

    int total_people = n + 1;
    int ways = 0;

    for (int dima = 1; dima <= 5; ++dima) {
        int total = sum_friends + dima;
        if (total % total_people != 1) {
            ways++;
        }
    }

    cout << ways << "\n";
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> days(n);
    for (int i = 0; i < n; ++i) {
        cin >> days[i];
    }

    const int INF = 1e9;
    vector<vector<int>> dp(n, vector<int>(3, INF));

    // Day 0
    dp[0][0] = 1; // Rest
    if (days[0] == 1 || days[0] == 3) dp[0][2] = 0; // Gym possible
    if (days[0] == 2 || days[0] == 3) dp[0][1] = 0; // Contest possible

    for (int i = 1; i < n; ++i) {
        // Rest
        dp[i][0] = min({dp[i-1][0], dp[i-1][1], dp[i-1][2]}) + 1;

        // Contest
        if (days[i] == 2 || days[i] == 3) {
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
        }

        // Gym
        if (days[i] == 1 || days[i] == 3) {
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
        }
    }

    cout << min({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << endl;

    return 0;
}

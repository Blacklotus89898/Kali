#include <iostream>
#include <vector>
#define ll long long

using namespace std;

int main() {
    int n = 0;

    cin >> n; // Read the number of players
    
    vector<ll> va(n, 0);
    vector<ll> vb(n, 0);

    for (int i = 0; i < n; ++i) {
        ll a = 0;
        cin >> a;
        va[i] = a; // Store the scores of team A
    }
    for (int i = 0; i < n; ++i) {
        ll a = 0;
        cin >> a;
        vb[i] = a; // Store the scores of team B
    }


    vector<vector<ll>> dp(n, vector<ll>(2, 0)); // Initialize a 2D DP array
    dp[0][0] = va[0]; // First player of team A
    dp[0][1] = vb[0]; // First player of team B

    if (n > 1) {
        dp[1][0] = va[1] + dp[0][1]; // First player of team A
        dp[1][1] = vb[1] + dp[0][0]; // First player of team B
    } else {
        cout << max(dp[0][0], dp[0][1]) << endl; // Output the maximum score for a single player
        return 0; // Exit if there's only one player
    }
    
    // dp[1][0] = va[1] + dp[0][1]; // First player of team B
    // dp[1][1] = vb[1] + dp[0][0]; // First player of team B

    ll res = 0;
    for (int i = 2; i < n; ++i) {
        dp[i][0] = va[i] + max(dp[i-1][1], dp[i-2][1]);
        dp[i][1] = vb[i] + max(dp[i-1][0], dp[i-2][0]);
        res = max(res, max(dp[i][0], dp[i][1]));
    }

    cout << res << endl; // Output the maximum score



    return 0;
}
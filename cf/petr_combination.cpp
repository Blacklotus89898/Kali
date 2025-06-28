#include <iostream>
#include <vector>

bool can_balance(const std::vector<int>& angles, int idx, int sum) {
    if (idx == angles.size()) {
        return sum % 360 == 0;
    }
    // Try both clockwise (+) and counterclockwise (-)
    return can_balance(angles, idx + 1, sum + angles[idx]) ||
           can_balance(angles, idx + 1, sum - angles[idx]);
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> angles(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> angles[i];
    }

    if (can_balance(angles, 0, 0)) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }

    return 0;
}

/*
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> angles(n);
    for (int& angle : angles) std::cin >> angle;

    // dp[i] = true means sum i (mod 360) is reachable
    std::vector<bool> dp(360, false);
    dp[0] = true; // Start with 0°

    for (int angle : angles) {
        std::vector<bool> next_dp(360, false);
        for (int i = 0; i < 360; ++i) {
            if (dp[i]) {
                next_dp[(i + angle) % 360] = true;                 // Clockwise
                next_dp[(i - angle + 360) % 360] = true;           // Counterclockwise
            }
        }
        dp = std::move(next_dp); // Update current dp
    }

    std::cout << (dp[0] ? "YES\n" : "NO\n");
    return 0;
}
*/
#include <iostream>

#define ll long long

bool backTrack(ll target, ll current) {
    if (current >= target) {
        if (current == target) {
            return true;
        } else if (current % 3 == 0) {
            return backTrack(target, current/3) || backTrack(target, 2*current/3);
        } else {
            return false;
        }
    } else {
        return false;
    }

}


int main() {
    int t = 0;
    std::cin >> t;

    while (t--) {
        ll n, m;

        std::cin >> n >> m;

        if (m > n) {
            std::cout << "NO" << std::endl;
        } else {
            if (backTrack(m, n)) {
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
        }

    }

    return 0;
}

// two optimization possible: memoization with visited
// use dfs to do the search instead: use queue + memoization
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Input handling
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    // Calculate the minimum cost
    int cost = 0;
    if (m * a > b) {
        cost = (n / m) * b + min((n % m) * a, b);
    } else {
        cost = n * a;
    }

    // Output the result
    cout << cost << endl;

    return 0;
}
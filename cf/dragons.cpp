#include <iostream>
#include <map>

using namespace std;

int main() {
    int s = 0;
    int n = 0;
    cin >> s >> n;
    map<int, int> dragons;    
    for (int i = 0; i < n; ++i) {
        int a = 0, b = 0;
        cin >> a >> b;
        dragons[a] += b; // Combine values for the same key
    }

    for (const auto& [a, b] : dragons) {
        if (s <= a) {
            cout << "NO" << endl;
            return 0;
        }
        s += b;
    }

    cout << "YES" << endl;
    return 0;
}

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>  // To use sort

using namespace std;

int main() {
    int n, k;
    int value;
    cin >> n >> k;
    vector<int> v(n);
    
    // Input the values
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    // Sort the vector in decreasing order
    sort(v.begin(), v.end(), greater<int>());

    value = v[k-1];
    
    if (value > 0) {
        // While the next value is the same as the kth value, increment k
        while (k < n && v[k] == value) {
            k++;
        }
    } else {
        // If the value is 0, keep decreasing k until you find a non-zero value
        while (k > 0 && v[k-1] == 0) {
            k--;
        }
    }

    cout << k;

    return 0;
}

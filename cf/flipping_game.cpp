#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// kadane's algorithm to find the maximum sum of a contiguous subarray
int maxOnesAfterFlip(vector<int>& arr) {
    int totalOnes = count(arr.begin(), arr.end(), 1);
    int maxGain = -1, currentGain = 0;

    for (int num : arr) {
        int value = (num == 0) ? 1 : -1;
        currentGain = max(value, currentGain + value);
        maxGain = max(maxGain, currentGain);
    }

    return totalOnes + maxGain;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << maxOnesAfterFlip(arr) << endl;
    return 0;
}
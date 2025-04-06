#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int combination(vector<int>& arr, vector<int>& subset, vector<vector<int>>& result, int index) {
    // Base case: if we've considered all elements
    if (index == arr.size()) {
        result.push_back(subset); // Store the current combination
        return 1; // Count this combination
    }

    // Exclude the current element
    int excludeCount = combination(arr, subset, result, index + 1);

    // Include the current element
    subset.push_back(arr[index]);
    int includeCount = combination(arr, subset, result, index + 1);
    subset.pop_back(); // Backtrack to restore subset for other paths

    // Return the total count of combinations (exclude + include)
    return excludeCount + includeCount;
}

int main() {
    vector<int> arr = {1, 2, 3, 4}; // Input array
    vector<vector<int>> result;    // Store all combinations
    vector<int> subset;            // Temporary subset

    // Generate all combinations and count them
    int totalCombinations = combination(arr, subset, result, 0);

    // Print all combinations
    for (const auto& subset : result) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    // Print the total number of combinations
    cout << "Total combinations: " << totalCombinations << endl;

    return 0;
}
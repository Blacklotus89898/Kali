#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool canPartition(vector<int>& nums, vector<int>& subsetSums, int index, int target) {
    if (index == nums.size()) {
        for (int sum : subsetSums)
            if (sum != target)
                return false;
        return true;
    }

    for (int i = 0; i < subsetSums.size(); ++i) {
        if (subsetSums[i] + nums[index] <= target) {
            subsetSums[i] += nums[index];
            if (canPartition(nums, subsetSums, index + 1, target))
                return true;
            subsetSums[i] -= nums[index];
        }
        // Skip duplicate state
        if (subsetSums[i] == 0)
            break;
    }

    return false;
}

int maxEqualSubsetSum(vector<int>& nums, int k) {
    int total = accumulate(nums.begin(), nums.end(), 0);
    if (total % k != 0)
        return -1;

    int target = total / k;
    sort(nums.rbegin(), nums.rend()); // Optional: large elements first for early pruning

    if (nums[0] > target)
        return -1;

    vector<int> subsetSums(k, 0);
    if (canPartition(nums, subsetSums, 0, target))
        return target;
    return -1;
}

void runTest(vector<int> nums, int k) {
    cout << "Array: ";
    for (int n : nums) cout << n << " ";
    cout << "\nSubsets: " << k << endl;

    int result = maxEqualSubsetSum(nums, k);
    if (result == -1)
        cout << "Cannot evenly distribute into " << k << " subsets.\n\n";
    else
        cout << "Maximum equal subset sum: " << result << "\n\n";
}

int main() {
    // Test Case 1
    runTest({4, 3, 2, 3, 5, 2, 1}, 4);  // Expected: 5

    // Test Case 2
    runTest({1, 2, 3, 5}, 2);  // Expected: -1

    // Test Case 3
    runTest({2, 2, 2, 2}, 2);  // Expected: 4

    // Test Case 4
    runTest({10, 20, 30}, 1);  // Expected: 60

    // Test Case 5
    runTest({1, 1, 1}, 4);  // Expected: -1

    return 0;
}

// TODO: give the maximum possible even distribution of the array
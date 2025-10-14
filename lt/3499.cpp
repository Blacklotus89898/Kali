class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2 * k) return false; // need at least 2 adjacent subarrays
        if (k == 1 && n >= 2) return true; 

        // Track current streak length of strictly increasing numbers
        int streak = 1;
        vector<int> good(n, 0); // good[i] = 1 if subarray ending at i is increasing of length k

        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1])
                ++streak;
            else
                streak = 1;

            if (streak >= k)
                good[i] = 1;
        }

     

        // Check if there are two adjacent increasing subarrays
        for (int i = 0; i + k < n; ++i) {
            if (good[i] && good[i + k])
                return true;
        }

        return false;
    }
};

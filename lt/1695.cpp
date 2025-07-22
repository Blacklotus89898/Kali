class Solution {
    public:
        int maximumUniqueSubarray(vector<int>& nums) {
            vector<int> lastIndex(10001, -1);
            int left = 0, currSum = 0, maxSum = 0;
    
            for (int right = 0; right < nums.size(); ++right) {
                int num = nums[right];
                if (lastIndex[num] >= left) {
                    // Remove elements up to the duplicate's previous index
                    while (left <= lastIndex[num]) {
                        currSum -= nums[left];
                        ++left;
                    }
                }
                lastIndex[num] = right;
                currSum += num;
                maxSum = max(maxSum, currSum);
            }
            return maxSum;
        }
    };
    
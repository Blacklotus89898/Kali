class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            // no value k
            // any value smaller than K
            int len = nums.size();
            int count = -1;
            int prev = -1;
            sort(nums.begin(), nums.end(), greater{});
            if (nums.back() < k)
                return -1;
            if (nums.back() > k)
                count++;
            for (int i = 0; i < len; ++i) {
                if (prev != nums[i])
                    count++;
                prev = nums[i];
            }
            return count;
        }
    };
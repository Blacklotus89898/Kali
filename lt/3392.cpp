class Solution {
    public:
        int countSubarrays(vector<int>& nums) {
            int len = nums.size();
            int res = 0;
            for (int i = 0; i < len-2; ++i) {
                if (2*(nums[i] + nums[i+2]) == nums[i+1]) {
                    res++;
                }
            }        
            return res;
        }
    };
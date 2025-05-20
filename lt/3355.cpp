class Solution {
    public:
        bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            int n = nums.size();
            vector<int> sub(n, 0);
    
            for (const auto& q : queries) {
                sub[q[0]]++;
    
                if(q[1] < n - 1) sub[q[1] + 1]--;
            }
    
            for(int i = 1; i < n; ++i) {
                sub[i] += sub[i - 1];
            }
           
            for(int i = 0; i < n; ++i) {
                if (sub[i] < nums[i] && nums[i] != 0) return false;
            }
    
            return true;
    
        }
    };
    
    /* Brute force, use prefix sum instead
     for (const auto& q : queries) {
                for(int i = q[0]; i <= q[1]; ++i) {
                    sub[i]++;
                }
            }
    
            for(int i = 0; i < nums.size(); ++i) {
                nums[i] -= sub[i];
            }
    
            for(const auto& num : nums) {
                if (num > 0) return false;
            }
    
            */
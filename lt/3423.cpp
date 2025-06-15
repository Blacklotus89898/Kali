class Solution {
    public:
        int maxAdjacentDistance(vector<int>& nums) {
            int curr = 0;
            // edge case first always
            curr = max(curr, abs(nums[nums.size()-1] - nums[0]));
    
            for(int i = 0; i < nums.size() -1 ; ++i) {
                curr = max(abs(nums[i]- nums[i+1]), curr);
            }
    
            
            return curr;
        }
    };
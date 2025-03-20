class Solution {
public:
    int minOperations(vector<int>& nums) {
        // 111001
        int counter = 0;
        int len = nums.size();

        for (int i = 0; i < len-2; ++i){
            if(nums[i] == 0) {
                // flip
                counter++;
                nums[i] = 1 - nums[i];  
                nums[i+1] = 1 - nums[i+1]; 
                nums[i+2] = 1 - nums[i+2]; 
            }
            
        } 
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum != len) return -1;
        return counter;
    }
};

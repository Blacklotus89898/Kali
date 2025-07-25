class Solution {
    public:
        int maxSum(vector<int>& nums) {
            int result = 0;
            int counter = 0;
            set<int> s;
            sort(nums.begin(),nums.end()); // possible to not sort
            for (const int& n: nums){
                if(s.find(n) == s.end() && n > 0 ) {
                    result += n;
                    s.insert(n);
                    counter++;
                }
            }
            if (counter == 0) {
                result = nums[nums.size() -1];
            }
    
            return result;
        }
    };
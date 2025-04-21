class Solution {
    public:
        int numberOfArrays(vector<int>& differences, int lower, int upper) {
            // given diff, and range, we can compute the max diff and tell if possible, then using the max diff we can tell the range
            long long absMax = 0;
            long long absMin = 0;
            long long curr = 0;
            int len = differences.size();
            
            for (int i = 0; i < len; ++i) {
                curr += differences[i];
                if (curr < absMin) absMin = curr;
                else if (curr > absMax) absMax = curr;
            }
            int diff = absMax - absMin;
            int range = upper - lower;
            if (diff > range) return 0;
    
            return range - diff + 1;
    
    
        }
    };
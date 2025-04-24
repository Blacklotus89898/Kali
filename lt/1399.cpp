class Solution {
    public:
        int countLargestGroup(int n) {
            unordered_map<int, int> m;
            int res = 0;
            int maxC = -1;
            for(int i = 1; i <= n; ++i) {
                int j = sumOfDigit(i);
                m[j]++;
                
            }
    
            for(const auto&[key, value]: m) {
                if (value > maxC) {
                    maxC = value;
                    res = 1;
                } else if (value == maxC) {
                    res++;
                } 
            }
    
            return res;
        }
    
    private:
        int sumOfDigit(int i) {
            int res = 0;
            while(i > 0) {
                res += i % 10;
                i /= 10;
            }
    
            return res;
        }
    };
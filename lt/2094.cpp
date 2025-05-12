class Solution {
    public:
        vector<int> findEvenNumbers(vector<int>& digits) {
            //even three digit number
            //append the result
            //sort the results
            vector<int> mpp(10, 0);
            for (int i = 0; i < digits.size(); i++) mpp[digits[i]]++;
            
            vector<int> res;
            for (int i = 1; i < 10; ++i) {
                if (mpp[i] == 0) continue;
                mpp[i]--;
                for (int j = 0; j < 10; ++j) {
                if (mpp[j] == 0) continue;
                mpp[j]--;
                    for (int k = 0; k < 9; k+=2) {
                        if (mpp[k] == 0) continue;
                        res.push_back(100*i + 10 *j + k);
                    }
                    mpp[j]++;
                }
                mpp[i]++;
            } 
            return res;
        }
    };
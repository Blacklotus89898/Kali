class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int, int> count;
            vector<vector<int>> freq(nums.size() + 1);
            for (int num : nums) {
                count[num]++;
            }
            for (pair<int, int> c : count) {
                freq[c.second].push_back(c.first);
            }
            vector<int> ans;
            for (int i = freq.size() - 1; i > 0; i--) {
                for (auto n : freq[i]) {
                    ans.push_back(n);
                    if (ans.size() == k) {
                        return ans;
                    }
                }
            }
            return ans;
        }
    };
    
    class Solution {
        public:
            vector<int> topKFrequent(vector<int>& nums, int k) {
                // Create a frequency map
                unordered_map<int, int> m;
                int len = nums.size();
        
                for (int i = 0; i < len; ++i) {
                    m[nums[i]]++;
                }
        
                // Move the frequency map to a vector for sorting
                vector<pair<int, int>> freqVec(m.begin(), m.end());
                
                // Sort the vector based on frequency in descending order
                sort(freqVec.begin(), freqVec.end(), [](pair<int, int>& a, pair<int, int>& b) {
                    return a.second > b.second; // Sort by frequency in reverse order
                });
        
                // Prepare the result vector with the top k frequent elements
                vector<int> res;
                for (int i = 0; i < k; ++i) {
                    res.push_back(freqVec[i].first);
                }
        
                return res;
            }
        };



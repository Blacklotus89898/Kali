class Solution {
    public:
        vector<int> maxSubsequence(vector<int>& nums, int k) {
            vector<pair<int, int>> pairs;
    
            for (int i = 0; i < nums.size(); ++i) {
                pairs.emplace_back(nums[i], i); // (value, index)
            }
    
            // Sort descending by value
            sort(pairs.begin(), pairs.end(), [](auto& a, auto& b) {
                return a.first > b.first;
            });
    
            // Take top-k and collect their indices
            vector<int> indices;
            for (int i = 0; i < k; ++i) {
                indices.push_back(pairs[i].second);
            }
    
            // Sort indices to preserve original order
            sort(indices.begin(), indices.end());
    
            // Build result using original order
            vector<int> res;
            for (int idx : indices) {
                res.push_back(nums[idx]);
            }
    
            return res;
        }
    };

    // Must sort it twice
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            // Pseudo code: writing your code in english
            vector<int> result;
            // Implementing the pseudo code

            return result;
    
        }
    };
    
    int main() {
        Solution s;
        vector<int> nums = {2, 7, 11, 15};
        int target = 9;
        vector<int> result = s.twoSum(nums, target);
        for (const auto& num : result) {
            cout << num << " ";
        }
        cout << endl;
        return 0;
    }    
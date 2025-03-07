#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
            vector<vector<int>>ans;
            int temp1=0, temp2=0;
            int n1 = nums1.size(), n2 = nums2.size();
            while(temp1<n1 && temp2<n2){
                if(nums1[temp1][0]==nums2[temp2][0]){
                    ans.push_back({nums1[temp1][0],nums1[temp1][1]+nums2[temp2][1]});
                    temp1++;temp2++;
                }
                else if(nums1[temp1][0]<nums2[temp2][0]){
                    ans.push_back({nums1[temp1][0],nums1[temp1][1]});
                    temp1++;               
                }
                else{
                    ans.push_back({nums2[temp2][0],nums2[temp2][1]});
                    temp2++;                
                }
            }
    
            while(temp1<n1){
                ans.push_back({nums1[temp1][0],nums1[temp1][1]});
                temp1++; 
            }
    
            while(temp2<n2){
                ans.push_back({nums2[temp2][0],nums2[temp2][1]});
                temp2++; 
            }
            return ans; 
        }
    };


int main() { 
    Solution s;
    vector<vector<int>> nums1 = {{1, 3}, {2, 4}, {5, 6}};
    vector<vector<int>> nums2 = {{1, 2}, {3, 5}, {7, 8}};
    vector<vector<int>> result = s.mergeArrays(nums1, nums2);
    for (const auto& num : result) {
        cout << num[0] << " " << num[1] << endl;
    }
    return 0;

}
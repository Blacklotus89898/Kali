#include <iostream>


int main() 
{


class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> m;
        for (const  char& c : s) {
            m[c]++;
        }

        vector<int> odd;
        vector<int> even;
        for (const pair<char, int>& p : m) {
            if (p.second % 2 == 1) {
                odd.push_back(p.second);
            } else {
                even.push_back(p.second);
            }
        }

        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());

        return odd[odd.size() -1 ] - even[0];

        // or biggest odd with smallest even
    }
};
    return 0;
}
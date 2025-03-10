#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        // given array of w/b blocks
        // return steps to get k consecutive b


        // 1. sliding window: count number of white blocks
        // 2. go over entire array
        // 3. return the smallest number of w
        int curr = 0;
        int mini = 0;
        int n = blocks.size();
        // init slider
        for (int i = 0; i < k; ++i) {
            if(blocks[i] == 'W') {
                curr++;
            }
        }
        mini = curr;

        for(int i = k; i < n; ++i) {
            if (blocks[i] == 'W') {
                curr++;
            }
            if (blocks[i-k] == 'W') {
                curr--;
            }
            mini = min(mini, curr);
        } 
        return mini;
    }
};


int main() {
  Solution S = Solution();
  string ss = "WWBBWWBWWBBBBWW";
  int k = 8;


  cout << S.minimumRecolors(ss, k) << endl;
  return 0;
}

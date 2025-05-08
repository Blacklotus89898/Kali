#include <iostream>
#include <vector>
#include <algorithm>


// 4 = 3,2,2,2,1 => 3! * 2!* * 2! 
// 8 = 7!, 2!, 2!, 2!

// other edge cases

int main() {
    int n = 0;
    std::string ss = "";



    std::cin >> n;
    std::cin >> ss;
    std::vector<int> nums;
    for (char x : ss) {

        if (x == '4') {
            nums.push_back(3);
            nums.push_back(2);
            nums.push_back(2);
        } 
        else if (x == '6') {
            nums.push_back(5);
            nums.push_back(3);
        }
        else if (x == '8') {
            nums.push_back(7);
            nums.push_back(2);
            nums.push_back(2);
            nums.push_back(2);
        }
        else if (x == '9') {
            nums.push_back(7);
            nums.push_back(3);
            nums.push_back(3);
            nums.push_back(2);
        }
        else if (x != '1' && x != '0') {
            nums.push_back(x - '0');
        }
    }
    std::sort(nums.begin(), nums.end(), std::greater<int>());
    for (int i = 0; i < nums.size(); ++i) {
        std::cout << nums[i];
    }
    return 0;
}
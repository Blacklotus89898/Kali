#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<int> applyOperations(vector<int> &nums)
{
    int n = nums.size();
    int writeIndex = 0; // Pointer to place non-zero elements

    for (int index = 0; index < n; index++)
    {
        // Step 1: Merge adjacent equal elements if they are non-zero
        if (index < n - 1 && nums[index] == nums[index + 1] &&
            nums[index] != 0)
        {
            nums[index] *= 2;
            nums[index + 1] = 0;
        }

        // Step 2: Shift non-zero elements to the front
        if (nums[index] != 0)
        {
            if (index != writeIndex)
            {
                swap(nums[index], nums[writeIndex]);
            }
            writeIndex++;
        }
    }

    return nums;
}

int main()
{
    vector<int> nums = {2, 2, 0, 4, 0, 8};
    vector<int> result = applyOperations(nums);
    for (const int &num : result)
    {
        cout << num << " ";
    }
    return 0;
}

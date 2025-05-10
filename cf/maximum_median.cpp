#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    int n = 0;
    int k = 0;
    std::cin >> n >> k;

    std::vector<int> nums(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    std::sort(nums.begin(), nums.end());

    int left = nums[n / 2], right = nums[n / 2] + k + 1;

    while (left < right) {
        int mid = left + (right - left + 1) / 2;
        long long required = 0;

        for (int i = n / 2; i < n; ++i) {
            if (nums[i] < mid) {
                required += mid - nums[i];
            }
        }

        if (required <= k) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }

    std::cout << left << std::endl;

    return 0;
}
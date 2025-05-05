#include <iostream>
#include <vector>
#include <algorithm>

int binarySearch(std::vector<int> &arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2; 

        if (arr[mid] == target)
        {
            return mid; 
        }
        else if (arr[mid] < target)
        {
            left = mid + 1; 
        }
        else
        {
            right = mid - 1; 
        }
    }

    return -1; // Target not found
}


void printArray(const std::vector<int> &arr)
{
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    std::cout << "Original array: ";
    printArray(arr);

    sort(arr.begin(), arr.end()); 

    int index = binarySearch(arr, 23);
    if (index != -1)
    {
        std::cout << "Element 23 found at index: " << index << std::endl;
    }
    else
    {
        std::cout << "Element not found in the array." << std::endl;
    }
    index = binarySearch(arr, 22);
    std::cout << "Element 22 found at index: " << index << std::endl;
    printArray(arr);
    
    return 0;
}
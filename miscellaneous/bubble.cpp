#include <iostream>
#include <vector>

// void bubbleSort(std::vector<int>& arr) {
//     int n = arr.size();
//     for (int i = 0; i < n - 1; ++i) {
//         for (int j = 0; j < n - i - 1; ++j) {
//             if (arr[j] > arr[j + 1]) {
//                 // Swap arr[j] and arr[j + 1]
//                 std::swap(arr[j], arr[j + 1]);
//             }
//         }
//     }
// }

void bubbleSort(std::vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
    {
        bool swapped = false; // Flag to check if any swapping occurred
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap arr[j] and arr[j + 1]
                std::swap(arr[j], arr[j + 1]);
                swapped = true; // Set the flag to true if swapping occurred
            }
        }
        if (!swapped) // If no two elements were swapped, the array is sorted
        {
            break;
        }
    }
}

// optimized bubble sort
// void bubbleSort(std::vector<int> &arr) {
//     int n = arr.size();
//     int lastSwap = n - 1; // Track the last swapped index
//     while (lastSwap > 0) {
//         int newSwap = 0; // Reset swap index
//         for (int j = 0; j < lastSwap; ++j) {
//             if (arr[j] > arr[j + 1]) {
//                 std::swap(arr[j], arr[j + 1]);
//                 newSwap = j; // Update last swapped index
//             }
//         }
//         lastSwap = newSwap; // Reduce the range for the next pass
//     }
// }




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

    bubbleSort(arr);

    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
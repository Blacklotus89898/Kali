#include <iostream>
#include <vector>

void insertionSort(std::vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int select = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > select ) {
            arr[j + 1] = arr[j]; //shifting up
            --j;
        }
        arr[j + 1] = select; // inserting the selected element in the right position
    }
}
// void insertionSort(std::vector<int> &arr)
// {
//     int n = arr.size();
//     for (int i = 1; i < n; ++i)
//     {
//         int key = arr[i];
//         int j = i - 1;
//         while (j >= 0 && arr[j] > key)
//         {
//             arr[j + 1] = arr[j];
//             --j;
//         }
//         arr[j + 1] = key;
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

    insertionSort(arr);

    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
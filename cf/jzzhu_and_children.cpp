#include <iostream>
#include <vector>

int main () {

    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    int result = 0; // Store the index of the last child
    int counter = 0; // Count number of children with candies <= 0

    while(counter != n) {
        counter = 0;
        for (int i = 0; i < n; ++i) { // Start from i = 0 to include all children
            if (a[i] > 0) {
                a[i] -= m;
                result = i; // Update result to the current child's index
            } 
            
            if (a[i] <= 0) {
                counter++;
            }
        }
    }

    std::cout << result + 1 << std::endl;


    return 0;
}
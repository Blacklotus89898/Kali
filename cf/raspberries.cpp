#include <iostream>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;
    
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        
        int min_ops = k;  // Upper bound: worst case is k-1 operations
        int count_even = 0;
        
        for (int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            
            // Check if already divisible
            if (x % k == 0) {
                min_ops = 0;
            } else {
                min_ops = std::min(min_ops, k - (x % k));
            }
            
            // For k=4, also count even numbers
            if (k == 4 && x % 2 == 0) {
                count_even++;
            }
        }
        
        // Special handling for k=4
        if (k == 4 && min_ops > 0) {
            if (count_even >= 2) {
                min_ops = 0;
            } else if (count_even == 1) {
                min_ops = std::min(min_ops, 1);
            } else {
                min_ops = std::min(min_ops, 2);
            }
        }
        
        std::cout << min_ops << std::endl;
    }
    
    return 0;
}
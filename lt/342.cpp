class Solution {
    public:
        bool isPowerOfFour(int n) {
            return n > 0 && (n & (n - 1)) == 0 && // Check if n is a power of 2
                   (n & 0x55555555) != 0; // Check if the only set bit is in the
                                          // correct position for power of 4
        }
    };
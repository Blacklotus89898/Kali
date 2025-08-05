class Solution {
    public:
        int numOfUnplacedFruits(std::vector<int>& fruits, std::vector<int>& baskets) {
            int counter = 0;
            int n = fruits.size();
    
            for (int i = 0; i < n; ++i) {
                bool placed = false;
    
                for (int j = 0; j < n; ++j) {
                    if (baskets[j] >= fruits[i]) {
                        baskets[j] = 0; // Mark basket as used
                        placed = true;
                        break;
                    }
                }
    
                if (!placed) counter++;
            }
    
            return counter;
        }
    };
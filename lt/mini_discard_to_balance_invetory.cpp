#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    int minArrivalsToDiscard(vector<int> &arrivals, int w, int m)
    {
        // arrivals
        // window size (start to i at most w width)
        // at most m times, so if m bigger or equal to w, then it always work, no discard
        // else, we need to check for the items to be discarded
        if (w <= m)
        {
            return 0;
        }
        else
        {
            // sliding window
            int discards = 0;

            // populate the window
            std::unordered_map<int, int> mm;
            for (int i = 0; i < w; i++)
            {
                if (mm[arrivals[i]] < m)
                {
                    mm[arrivals[i]]++;
                }
                else
                {
                    discards++;
                    arrivals[i] = -1; // discarded
                }
            }

            for (int i = w; i < arrivals.size(); ++i)
            {
                mm[arrivals[i - w]]--;
                if (mm[arrivals[i]] < m)
                {
                    mm[arrivals[i]]++;
                }
                else
                {
                    discards++;
                    arrivals[i] = -1;
                }
                
            }

            return discards;
        }
    }
};

int main()
{
    Solution sol;

    std::vector<int> arrivals1 = {1, 2, 1, 3, 1};
    std::cout << sol.minArrivalsToDiscard(arrivals1, 4, 2) << "\n"; // Expected: 0

    std::vector<int> arrivals2 = {1, 2, 3, 3, 3, 4};
    std::cout << sol.minArrivalsToDiscard(arrivals2, 3, 2) << "\n"; // Expected: 1

    std::vector<int> arrivals3 = {1, 1, 1, 1, 1};
    std::cout << sol.minArrivalsToDiscard(arrivals3, 2, 1) << "\n"; // Expected: 3

    return 0;
}

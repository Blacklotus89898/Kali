#include <iostream>
#include <vector>
#include <unordered_map>
typedef long long ll;

using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    while (t-- > 0)
    {
        ll n = 0;
        cin >> n;
        vector<ll> nums(n, 0);
        for (ll k = 0; k < n; ++k)
        {
            cin >> nums[k];
        }

        // use a map and store the value
        ll counter = 0;
        unordered_map<ll, ll> index_map;

        // Store indices of elements in a map for quick lookup
        for (ll i = 0; i < n; ++i)
        {
            index_map[nums[i]] = i + 1; // Store 1-based index
        }

        // Iterate through the array and check for valid pairs
        for (ll i = 1; i <= n; ++i)
        {
            for (ll j = nums[i - 1] - i; j <= n; j += nums[i - 1])
            {
                if (j > i && j <= n && nums[i - 1] * nums[j - 1] == i + j)
                {
                    counter++;
                }
            }
        }

        cout << counter << endl;
    }
    return 0;
}

/* Brute force solution, O(n^2)
   for each pair (i, j) check if nums[i] * nums[j] == i + j + 2
   where i and j are 0-indexed, so we add 2 to match the problem statement

 int counter = 0;
    for(int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (nums[i] * nums[j] == i + j + 2) {
                counter++;
            }
        }
    }

    cout << counter << endl;


*/
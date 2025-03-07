#include <iostream>
#include <vector>

using namespace std;

int get_row(int n)
{
    int row = 0;
    while (n > row)
    {
        row++;
        n -= row;
    }
    return row;
}

vector<int> pacal_Dp(int n, vector<int> dp)
{
    int row = 0;
    int l = 0;
    int r = 0;

    for (int i = 0; i < n; ++i)
    {
        row = get_row(i);
        if (row == 0)
        {
            // Base case
            dp[i] = 1;
            l = 1;
            r = 2;
        }
        else
        {

            if (i != l)
            {
                dp[i] += dp[i - row - 1];
            }
            else
            {
                l += row + 1;
            }

            if (i != r)
            {
                dp[i] += dp[i - row];
            }
            else
            {
                r += row + 2;
            }
        }
    }

    return dp;
}

/*
1
11
121
1331
14641

1, 1, 1, 1, 2, 1, 1, 3, 3, 1, 1, 4, 6, 4, 1
*/

void print_result(vector<int> dp)
{
    // make it print in a binary way
    int index = 1;
    int rl = 1;
    for (const auto &num : dp)
    {
        cout << num << " ";
        if (index % rl == 0)
        {
            index -= rl;
            rl += 1;
            cout << "row length: " << rl;
            cout << endl;
        }
        index++;
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n, 0);
    dp = pacal_Dp(n, dp);

    print_result(dp);

    // cin >> n;
    // cout << "orw" << get_row(n) << endl;
    // return 0;
}
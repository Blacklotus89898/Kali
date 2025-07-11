#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;

    while (t--)
    {

        int n = 0;
        int balance = 0;
        int move = 0;
        string s = "";
     
        cin >> n >> s;
     
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == ')')
            {
                balance++;
                if (balance > 0)
                {
                    move++;
                    balance = 0;
                }
            }
            else
            {
                balance--;
            }
        }
        cout << move << endl;
    }

    return 0;
}

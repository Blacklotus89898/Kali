#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int n = 0, t = 0;
    cin >> n >> t;

    vector<int> v(n - 1);
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> v[i];
    }

    int index = 0;
    while (index + 1 < t)
    {
        index += v[index];
    }

    if (index + 1 == t)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}

// 8 4
// 1 2 1 2 1 2 1

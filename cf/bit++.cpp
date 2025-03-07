#include <iostream>
#include <vector>
#include <string>

using namespace std;

void operation(int n)
{
    vector<string> statements(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> statements[i];
    }
    int x = 0;
    for (const auto &statement : statements)
    {
        if (statement.find("++") != string::npos)
        {
            x++;
        }
        else
        {
            x--;
        }
    }
    cout << x << endl;
}

int main()
{
    int n;
    cin >> n;
    operation(n);
    return 0;
}

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n >= 0) cout << 0 << endl;
    if (n >= 1) cout << 1 << endl;

    int num1 = 0, num2 = 1, num3;
    for(int i = 2; i <= n; ++i) {
        num3 = num1 + num2;
        num1 = num2;
        num2 = num3;
        cout << num3 << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    // compute the diff between the num
    // find the lower num to achieve the diff
    int count = 0;

    while(n != m) {
        if (m < n) {
            count += n - m;
            break;
        } else if (m % 2 == 0) {
            count++;
            m /= 2;
        } else {
            count++;
            m += 1;
        }
    }

    cout << count << endl;

    return 0;
}

#include <iostream>
#include <set>
#include <string>

using namespace std;


int main() {
    string ss;
    cin >> ss;

    if (ss[0] >= 'a' && ss[0] <= 'z') {
        ss[0] = ss[0] - 'a' + 'A';
    }

    for(int i = 0; i < ss.size(); ++i) {
        cout << ss[i];
    }

    return 0;
}

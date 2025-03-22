#include <iostream>
#include <set>
#include <string>

using namespace std;


int main() {
    set<char> s;

    string ss;
    cin >> ss;

    for(int i = 0; i < ss.size(); ++i) {
        s.insert(ss[i]);
    }

    if (s.size() % 2 == 0) {
        cout << "CHAT WITH HER!";
        return 0;

    }

    cout << "IGNORE HIM!";

    return 0;
}

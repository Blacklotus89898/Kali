#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main () {
    string s;
    vector<int> v;

    cin >> s;
    // parse the string into vector
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] != '+') {
            v.push_back(s[i] - '0');
        }
    }

//sorting
    for(int i = 0; i < v.size(); ++i) {
        bool swap = false;
        for (int j = 1; j < v.size() -i; ++j) {

            if (v[j-1] > v[j]) {
                int t = v[j];
                v[j] = v[j-1];
                v[j-1] = t;
                swap = true;
            }
        }
        if(!swap) {
        break;
        }
    }

    for(int i = 0; i < v.size()-1; ++i) {
        cout << v[i] << "+";
    }
    cout << v[v.size()-1];


    return 0;
}


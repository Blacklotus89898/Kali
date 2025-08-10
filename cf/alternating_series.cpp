#include <iostream>
#define ll long long
using namespace std;




int main() {

    // -1 and 3, keep in mind the edge case 
    // alternating signs ll array
    // sum of all subarray of at least length 2 must be positive > 0
    //

    ll t = 0;

    cin >> t;

    while(t--) {


        ll n = 0;
        cin >> n;

        // cout << "result for debugging:";

        if (n == 2) {
            cout << "-1 " << "2" << endl;
        }  else {
            for (ll i = 0; i < n; ++i) {
                if (i % 2 == 0) {
                    cout << -1 << " ";
                } else if (i == n -1 && n % 2 == 0) {
                    cout << 2 << " ";
                } else {
                    cout << 3 << " ";
                }
            }
            cout << endl;
        }

    }


    return 0;
}

// -1 3 -1 2 
// -1 3 -1 3 -1 3 -1 2
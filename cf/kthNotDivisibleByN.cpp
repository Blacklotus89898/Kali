#include <iostream>
#include <string>
#include <vector>

#define ll long long

using namespace std;


int main () {
    int t;
    ll n, k;

    cin >> t;

    for (int i = 0; i < t; ++i) {
        cin >> n >> k;
        // Calculate the k-th number not divisible by n
        ll ans = k + (k - 1) / (n - 1);

        cout << ans << endl;

       
    }

    return 0;
}


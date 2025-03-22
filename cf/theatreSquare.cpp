#include <iostream>
typedef long long ll;

using namespace std;


int main() {
    ll n, m, a;
    cin >> n >> m >> a;

    ll l = (m + a - 1) / a;
    ll w = (n + a - 1) / a; 
    

    cout <<  l * w;


    return 0;
}

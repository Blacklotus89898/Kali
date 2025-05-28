#include <iostream>
#include <cmath>
#define ll long long

int main() {


    ll r = 0;
    ll xa = 0, ya = 0;
    ll xb = 0, yb = 0;
    std::cin >> r >> xa >> ya >> xb >> yb;

    double distance = sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));

    std::cout << ceil(distance / (2 * r)) << std::endl;



    return 0;
}
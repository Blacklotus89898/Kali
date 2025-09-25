#include <iostream>

#define ll long long

int main() {


    //if a is > b/x then we have -1
    // if a < b/x then we have -1 for b

    int t = 0;
    std::cin >> t;
    while (t--) {

        ll a, b, c;
        std::cin >> a >> b >> c;
        double unit_b =  static_cast<double>(c) / b;
        
        int resa = a < c ?  1 : -1; //always true since 
        int resb = -1;

        if (unit_b < a ) {
            resb = b;
        }

        std::cout << resa << " " << resb << std::endl;

    }

    return 0;
}
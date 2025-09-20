#include <iostream>
#include <vector>

#define ll long long 

int main() {
    int t = 0;
    std::cin >> t;

    while (t--) {
        int n = 0;
        std::cin >> n;

        std::vector<ll> v (n, 0);
        for (int i = 0; i < n; ++i) {
            std::cin >> v[i];
        }

        if(n == 2) {
            std::cout << (v[0] == v[1] ? 1 : 2 ) << std::endl;
        } else {

            ll curr = v[0];
            int direction = 0;
            int b = 0;
            //track direction breaks
            for (int i = 1; i < n; ++i)  {
                if (curr < v[i]) {
                    if (direction == -1) {
                        b++;
                    }
                    direction = 1;
                } else if (curr > v[i]) {
                    if (direction == 1) {
                        b++;
                    }
                    direction = -1;
                } 
                curr = v[i];
            }

            if (b == 0 && direction == 0) {
                b = 1;
            } else {
                b += 2;
            }

            std::cout << b << std::endl;

        }


        
    }

    return 0;
}
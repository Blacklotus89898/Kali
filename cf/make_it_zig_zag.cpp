#include <iostream>
#include <vector>

#define ll long long

int main(){
    int t = 0;
    std::cin >> t;
    
    while (t--) {
        int n = 0;
        std::cin >> n;

        std::vector<ll> a (n, 0);

        ll m_e = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            m_e = std::max(m_e, a[i]);
            if ((i % 2) - 1 == 0) {
                a[i] = m_e; //do a prefix stuff
            }
        }

        ll res = 0;
        for (int i = 0; i < n; i += 2) {
            ll temp = 0;
            if (i != n-1) {
                temp = std::max(0LL, a[i] - a[i+1]+1);
            }

            if (i != 0) {
                temp = std::max(temp,a[i] - a[i-1]+1);
            }

            res += temp;
        }
     
 
        std::cout << res << std::endl;
    }

    return 0;
}

// get the max of even for free --- took soomuch time to udnerstand ripo
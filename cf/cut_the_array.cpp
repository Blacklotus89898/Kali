#include <iostream>
#include <vector>


int main() {
    int t = 0;
    std::cin >> t;
    
    while(t--) {
        int n = 0;
        std::cin >> n;
        
        int sum = 0;
        std::vector<int> v(n, 0);
        for(int i = 0; i < n; ++i) {
            std::cin >> v[i];
            sum += v[i];
        }

        int p = 0;
        int c = 0;
        int s = 0;

        int l = 0;
        int r = 0;

        bool found = false;
        for (int i = 0; i < n-2; ++i) {
            if (found) break;
            p += v[i];
            c = 0;
            for (int j = i+1; j < n-1; ++j) {
                c +=  v[j];
                s = sum - p - c;
                if ((s % 3 == p % 3 && p % 3 == c % 3) || (s % 3 != p % 3 && s % 3 != c % 3 && p % 3 != c % 3)) {
                    found = true;
                    l = i;
                    r = j;
                    break;
                }
            }
        }

       if(found) {
           std::cout << l+1  << " " <<  r+1 << std::endl;
        } else {            
            std::cout << 0  << " " <<  0 << std::endl;
       }
        
    }

}
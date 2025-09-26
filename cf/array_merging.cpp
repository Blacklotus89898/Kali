#include <iostream>
#include <vector>
#include <unordered_map>

int main() {

    int t = 0;
    std::cin >> t;
    while (t--) {

        int n = 0;
        std::cin >> n; 
        std::vector<int> a (n,0);
        std::vector<int> b (n,0);
        std::unordered_map<int, int> fa;
        std::unordered_map<int, int> fb;

        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];

        }


        for (int i = 0; i < n; ++i) {
            std::cin >> b[i];

        }

        int currA = a[0];
        int cA = 1;
        int currB = b[0];
        int cB = 1;

        for (int i = 1; i < n; ++i) {
            if (currA == a[i]) {
                cA++;
            } else {
                fa[currA] = std::max(fa[currA], cA);
                cA = 1;
                currA = a[i];
            }
            if (currB == b[i]) {
                cB++;
            } else {
                fb[currB] = std::max(fb[currB], cB);
                cB = 1;
                currB = b[i];
            }
        }
        
        fa[currA] = std::max(fa[currA], cA);
        fb[currB] = std::max(fb[currB], cB);
        

        int res = 0;
        for (int i = 0; i < 2*n+1; ++i) {
            res = std::max(res, fb[i]+fa[i]);
        }

        std::cout << res << std::endl;


    }

    return 0;
}
#include <iostream>
#include <set>

int main() {

    int t = 0;
    std::cin >> t;
    while (t--) {
        int n = 0;
        std::cin >> n;

        std::set<int> s;
        for (int i = 0; i < n; ++i) {
            int x = 0;
            std::cin >> x;
            s.insert(x);
        }

        if (s.size() < n) {
            std::cout << "YES" << '\n';
        } else {
            std::cout << "NO" << '\n';
        }






        // s * t /t


        

    
    }

    return 0;
}
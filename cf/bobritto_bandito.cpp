#include <iostream>

int main() {
    int t = 0;
    std::cin >> t;
    while(t-- > 0) {
        int n, m, l, r;
        std::cin >> n >> m >> l >> r;
        int right = 0, left = 0;
        while ( m > 0){
            if(l < right) {
                right--;
                m--;
            } else {
                left++;
                m--;
            }
            //std::cout << "loop";

        }
    std::cout << right << " " << left << std::endl;
    }


    return 0;
}

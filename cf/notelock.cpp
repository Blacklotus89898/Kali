#include <iostream>
#include <vector>

// Just brute force
int main(){
    int t = 0;
    std::cin >> t;

    while (t--) {

        int n, k;
        std::cin >> n >> k; // k - 1 element wtf? of original string assuming 
        
        std::string s;
        std::cin >> s;        
        
        int res = 0;

        for (int i = 0; i < n; ++i) {
            // brute force fakoff O(nk)
            if (s[i] == '1') {
                bool locked = false;
                for (int j = std::max(0, i - k + 1); j < i; ++j) {
                    if (s[j] == '1') {
                        locked = true;
                        break;
                    }
                } 
                if (!locked) res++;
            }
        }

        std::cout << res << std::endl;

    }

    return 0;
}
// int main(){
//     int t = 0;
//     std::cin >> t;

//     while (t--) {

//         int n, k;
//         std::cin >> n >> k; // k - 1 element wtf? of original string assuming 
        
//         std::string s;
//         std::cin >> s;        
        
//         int res = 0;
//         // setup
//         for (int i = 1; i < k; ++i) {
//             if (s[0] == '1') {
//                 if (s[i] == '1') {
//                     s[i] = '2'; // it is locked
//                 } 
//             }
//         }

//         for (int i = 0; i < n; ++i) {
//             if (s[i] == '1') {
//                 res++;
//                 if (s[std::min(n-1,i+k-1)] == '1') {
//                     s[std::min(n-1,i+k-1)] = '2';
//                 }
//             } else if (s[i] == '2') {
//                 if (s[std::min(n-1,i+k-1)] == '1') {
//                     s[std::min(n-1,i+k-1)] = '2';
//                 }
//             }
//         }
//         std::cout << res << std::endl;

//     }

//     return 0;
// }

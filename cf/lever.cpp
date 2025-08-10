#include <iostream>
#include <vector>

using namespace std;



int main() {
    int t = 0;
    cin >> t;

    while (t--) {

        int n = 0;
        cin >> n;

        vector<int> a(n);
        vector<int> b(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        
        int iter = 1; //always need at least one iteration

        for (int i = 0; i < n; ++i) {
            if (a[i] > b[i]) {
                iter += a[i] - b[i];
            }
        }   

        std::cout << iter << std::endl;

        
    }


    return 0;
}
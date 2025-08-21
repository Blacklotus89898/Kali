#include <iostream>

int main() {

    int t = 0; // less equal 1000
    std::cin >> t;

    while(t--) {

        int n = 0; //less than 11
        std::cin >> n;
        
        std::string a = "";
        std::cin >> a;


        int m = 0;
        std::cin >> m;
        
        std::string b = "";
        std::cin >> b;
        
        std::string c = "";
        std::cin >> c;
        
        for (int i = 0; i < m; ++i) {
            if(c[i] == 'D') {
               a += b[i];     
            } else {
                a = b[i] + a;
            }
        }

        std::cout << a << std::endl;
        
    }


    return 0;
}
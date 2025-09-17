#include <iostream>
#include <vector>

#define ll long long

int main() {
    int t = 0;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<std::vector<ll>> matrix (n, std::vector<ll> (m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                std::cin >> matrix[i][j];

            }
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ll lowest = 0;
                if (i > 0) {
                    lowest = std::max(matrix[i-1][j], lowest);
                } 
                if (i < n-1) {
                    lowest = std::max(matrix[i+1][j], lowest);
                    
                }
                if (j > 0) {
                    lowest = std::max(matrix[i][j-1], lowest);
                    
                }
                if (j < m-1) {
                    lowest = std::max(matrix[i][j+1], lowest);
                }
                matrix[i][j] = std::min(lowest, matrix[i][j]);
                
            }
        }
        
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                std::cout << matrix[i][j] << " ";

            }
            std::cout << std::endl;
        }
        
        
    }
}
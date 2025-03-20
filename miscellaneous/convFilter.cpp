#include <iostream>
#include <vector> 
using namespace std;

int main() {
  // TODO:
  // 1. Setup matrix, filter
  // 2. Implement the loop
  // 3. Handle edge cases (zero matrix, same size, smaller, non-square)
  vector<vector<int>> matrix = {{0, 1,2}, {3, 4,5}, {6, 7,8}};
  vector<vector<int>> filter = {{0,1}, {2, 3}};

  int N = matrix.size(); //rows
  int D = matrix[0].size();

  //need filter dimension
  int m = filter.size();
  int n = filter[0].size();

  //result initialization
  vector<vector<int>> result(N-m+1, vector<int>(D-n+1, 0));
  // rethink a better computation approach
  if (D >= n && N >= m) {

    for (int i = 0; i <= N - m; ++i) {
      for (int j =  0; j <= D - n; ++j) {

        for (int a = 0; a < m; ++a) {
          for (int b = 0; b < n; ++b) {
            result[i][j] += matrix[i+a][j+b] * filter[a][b];
          }
        }


      }
    }
    // Print the result matrix
    for (const auto& row : result) {
      for (const auto& val : row) {
        cout << val << " ";
      }
      cout << endl;
    }
  }

  return 0;
}

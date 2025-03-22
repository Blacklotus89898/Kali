#include <iostream>
#include <vector>

using namespace std;

int main() {

    int N, M;

    cin >> N >> M;
    vector<vector<char > > matrix(N, vector<char>(M));

    vector<char> res;

   // Read the matrix input
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> matrix[i][j];  // Read the matrix values
        }
    }

    // Vector to store the result (non '.' characters)

    // Traverse the matrix column by column
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (matrix[j][i] != '.') {
                res.push_back(matrix[j][i]);  // Collect non '.' characters
            }
        }
    }

    for(int i = 0; i < res.size(); ++i) {

        cout << res[i];

    } 

    return 0;
}

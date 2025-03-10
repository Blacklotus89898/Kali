#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<vector<int>> matrix(5, vector<int>(5));
    int m, n;

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 1) {
                m = i;
                n = j;
            }
        }
    }

    cout << abs(2 - m) + abs(2 - n) << endl;

    return 0;
}
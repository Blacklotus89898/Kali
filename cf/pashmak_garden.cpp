#include <iostream>
#include <vector>

using namespace std;
int main() {
    vector<pair<int, int>> garden;

    for (int i = 0; i < 2; ++i) {
        int x, y;
        cin >> x >> y;
        garden.push_back(make_pair(x, y));
    }

    // need to determine the corner
    int dx = garden[1].first - garden[0].first;   
    int dy = garden[1].second - garden[0].second;   

    if (abs(dx) != abs(dy) && dx != 0 && dy != 0) {
        cout << -1 << endl;
        return 0;
    }

    if (abs(dx) == abs(dy)) {
        // diagonal
        cout << garden[0].first + dx << " " << garden[0].second  << " ";
        cout << garden[0].first  << " " << garden[0].second + dy << endl;
    } else if (dx == 0) {
        // vertical line
        cout << garden[0].first + dy << " " << garden[0].second << " ";
        cout << garden[1].first + dy << " " << garden[1].second << endl;
    } else if (dy == 0) {
        // horizontal line
        cout << garden[0].first << " " << garden[0].second + dx << " ";
        cout << garden[1].first << " " << garden[1].second + dx << endl;

    }

    return 0;
}
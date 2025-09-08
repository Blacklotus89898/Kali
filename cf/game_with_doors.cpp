#include <iostream>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int l, r, L, R;
        std::cin >> l >> r >> L >> R;

        // compute overlap length
        int left = std::max(l, L);
        int right = std::min(r, R);

        int door = 0;
        if (left <= right) {
            door = right - left + 1; // number of integers in overlap
        }

        // adjustments (based on your conditions)
        if (l == L && r == R) {
            door--; // identical segments
        } else if ((l < L && r > R) || (r < R && l > L)) {
            door++; // one interval contained in the other
        } else if ((l < L && r < R) || (r > R && l > L)) {
            door++;
        }

        std::cout << door << "\n";
    }

    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    int t = 0;
    std::cin >> t;

    while (t--) {
        std::string s;
        std::cin >> s;
        std::string original = s;

        int n = s.size();
        std::vector<bool> used(n, false);
        int i = 0, j = 0;

        while (true) {
            // find next '1' that hasn't been swapped
            while (i < n && (s[i] != '1' || used[i])) i++;

            // find next '0' that hasn't been swapped
            while (j < n && (s[j] != '0' || used[j])) j++;

            if (i < n && j < n) {
                // swap positions i and j
                std::swap(s[i], s[j]);
                used[i] = used[j] = true;
                i++;
                j++;
            } else {
                break;
            }
        }

        // count unchanged positions
        int unchanged = 0;
        i = 0;
        j = 0;
        while (i < n) {
            while (s[i] == original[j] && i < n && j < n) {
                unchanged++;
                i++;
            }
            j++;
            i++;
        }

        // std::cout << s << "\n";
        // std::cout << original << "\n";
        std::cout << unchanged << "\n";
    }

    return 0;
}

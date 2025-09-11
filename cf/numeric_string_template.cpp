#include <iostream>
#include <vector>
#include <unordered_map>

#define ll long long

int main() {
    int t = 0;
    std::cin >> t;

    while (t--) {
        int n = 0;
        std::cin >> n;

        std::vector<ll> a(n, 0);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        int q = 0;
        std::cin >> q;

        for (int i = 0; i < q; ++i) {
            std::string s;
            std::cin >> s;

            if ((int)s.size() != n) {
                std::cout << "NO" << std::endl;
                continue;
            }

            std::unordered_map<ll, char> numToChar;
            std::unordered_map<char, ll> charToNum; //ensure 1 to 1 mapping, can be replaced by vector instead of string
            bool isValid = true;

            for (int j = 0; j < n; ++j) {
                ll num = a[j];
                char c = s[j];

                if (numToChar.find(num) == numToChar.end() && charToNum.find(c) == charToNum.end()) {
                    // new mapping both ways
                    numToChar[num] = c;
                    charToNum[c] = num;
                } else {
                    // check consistency both ways
                    if (numToChar[num] != c || charToNum[c] != num) {
                        isValid = false;
                        break;
                    }
                }
            }

            std::cout << (isValid ? "YES" : "NO") << std::endl;
        }
    }

    return 0;
}

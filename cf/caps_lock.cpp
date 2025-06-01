#include <iostream>
#include <string>
#include <cctype> // For std::isupper and std::islower

int main() {
    std::string s;
    std::cin >> s;

    // Check if all characters except the first are uppercase
    bool allUpperExceptFirst = true;
    for (size_t i = 1; i < s.size(); ++i) {
        if (!std::isupper(s[i])) {
            allUpperExceptFirst = false;
            break;
        }
    }

    // If the condition is met, toggle the case of all characters
    if (allUpperExceptFirst) {
        for (char &c : s) {
            if (std::islower(c)) {
                c = std::toupper(c);
            } else {
                c = std::tolower(c);
            }
        }
    }

    std::cout << s << std::endl;
    return 0;
}

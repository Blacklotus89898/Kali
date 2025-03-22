#include <iostream>
#include <string>
using namespace std;

int binaryToInt(const string& binaryStr) {
    int decimalValue = 0;
    for (char c : binaryStr) {
        decimalValue *= 2;  // Shift left by 1 bit (multiply by 2)
        if (c == '1') decimalValue += 1;
        else if (c == '0') continue;
        else {
            cerr << "Invalid binary character: " << c << endl;
            return -1;  // Error handling
        }
    }
    return decimalValue;
}




int main() {
    string binaryStr;  // Example binary string

    cin >> binaryStr;
    // Convert binary string to integer using stoi with base 2
    int decimalValue = stoi(binaryStr, nullptr, 2);

    cout << "Binary: " << binaryStr << " -> Decimal: " << decimalValue << endl;
    return 0;
}


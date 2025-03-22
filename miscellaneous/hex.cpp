#include <iostream>
#include <string>
using namespace std;

int hexToInt(const string& hexStr) {
    int decimalValue = 0;
    for (char c : hexStr) {
        decimalValue *= 16;  // Shift left by 4 bits (multiply by 16)
        if (c >= '0' && c <= '9') decimalValue += (c - '0');
        else if (c >= 'A' && c <= 'F') decimalValue += (c - 'A' + 10);
        else if (c >= 'a' && c <= 'f') decimalValue += (c - 'a' + 10);
        else {
            cerr << "Invalid hex character: " << c << endl;
            return -1;  // Error handling
        }
    }
    return decimalValue;
}


int main() {
    string hexStr;  // Example hex string

    cin >> hexStr;

    // Convert hex string to integer using stoi with base 16
    int decimalValue = stoi(hexStr, nullptr, 16);

    cout << "Hex: " << hexStr << " -> Decimal: " << decimalValue << endl;
    return 0;
}

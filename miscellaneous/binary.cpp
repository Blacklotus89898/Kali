#include <iostream>
#include <string>
using namespace std;

int main() {
    string binaryStr;  // Example binary string

    cin >> binaryStr;
    // Convert binary string to integer using stoi with base 2
    int decimalValue = stoi(binaryStr, nullptr, 2);

    cout << "Binary: " << binaryStr << " -> Decimal: " << decimalValue << endl;
    return 0;
}


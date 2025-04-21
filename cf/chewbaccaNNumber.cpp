#include <iostream>
#include <string>
#include <vector>

#define ll long long


using namespace std;


int main() {
    // ll x;
    // cin >> x;

    // string result = ""; // To store the transformed number as a string
    // string num = to_string(x); // Convert the number to a string for easy digit manipulation

    // for (size_t i = 0; i < num.size(); ++i) {
    //     int digit = num[i] - '0'; // Convert character to integer

    //     // Invert the digit if it's greater than 4
    //     if (digit > 4) {
    //         digit = 9 - digit;
    //     }

    //     // Ensure the first digit is not zero
    //     if (i == 0 && digit == 0) {
    //         digit = num[i] - '0'; // Keep the original digit
    //     }

    //     result += to_string(digit); // Append the transformed digit to the result
    // }

    // cout << result << endl; // Output the final transformed number

    // return 0;

    ll x;
    cin >> x;

    ll result = 0;
    ll multiplier = 1;

    while (x > 0) {
        int digit = x % 10; // Extract the last digit
        x /= 10;            // Remove the last digit from x

        // Invert the digit if it's greater than 4
        if (digit > 4) {
            digit = 9 - digit;
        }

        // Ensure the first digit (most significant) is not zero
        if (x == 0 && digit == 0) {
            digit = 9; // Keep the original digit if it's the most significant
        }

        // Build the result number
        result += digit * multiplier;
        multiplier *= 10;
    }

    cout << result << endl;

    return 0;
}


#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
    public:
        bool isValid(string s) {
            stack<char> st; 
            for(char c : s) {
                if (c == '(' || c == '{' || c == '[') {
                    st.push(c); // Push opening brackets onto the stack
                } else {
                    if (st.empty()) return false; // No matching opening bracket
                    char top = st.top(); // Get the top element of the stack
                    st.pop(); // Remove the top element from the stack
                    // Check for matching brackets
                    if ((c == ')' && top != '(') || 
                        (c == '}' && top != '{') || 
                        (c == ']' && top != '[')) {
                        return false; // Mismatched brackets
                    }
                }
            }
            return st.empty(); // If stack is empty, all brackets matched
        }
    };


int main() {


    Solution s;
    string str = "([{}])";
    cout << s.isValid(str) << endl; // Expected output: 1 (true)
    return 0;
}
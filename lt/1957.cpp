class Solution {
    public:
        string makeFancyString(string s) {
            int counter = 0;
            char cur = s[0];
            string result = "";
            for (const char& c : s) {
                if (c != cur || counter < 2) {
                    result += c;
                    c == cur ? counter++ : counter = 1;
                    cur = c;
                }
            }
            return result;
        }
    };
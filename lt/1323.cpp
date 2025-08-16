class Solution {
    public:
        int maximum69Number(int num) {
            int res = 0;
            string s = std::to_string(num);
            bool flag = false;
            string ss = "";
            for (const char& c : s) {
                if (c == '6' && !flag) {
                    ss += '9';
                    flag = true;
                } else {
                    ss += c;
                }
            }
    
            res = std::stoi(ss);
    
            return res;
        }
    };
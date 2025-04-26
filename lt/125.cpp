class Solution {
    public:
        bool isPalindrome(string s) {
            string ss = "";
            for (char c: s) {
                if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
                    if (c >= 'A' && c <= 'Z') {
                        c += 'a' - 'A';
                    } 
                    
                    ss += c;
                    
                }
            }
            int len = ss.size();
            for (int i = 0; i < len/2; ++i) {
                if(ss[i] != ss[len-i-1]) {
                    return false;
                }           
            }
    
            return true;
        }
    };
    

    // Slower solution below: 
    // class Solution {
    //     public:
    //         bool isPalindrome(string s) {
    //             int len = s.size();
    //             int l = len - 1;
    //             int f = 0;
    //             while (f < l) {
    //                 while (!isalnum(s[f]) && f < l) {
    //                     f++;
    //                 }
    //                 while (!isalnum(s[l]) && l > f) {
    //                     l--;
    //                 }
    //                 if (tolower(s[f]) != tolower(s[l])) {
    //                     return false;
    //                 } else {
    //                     f++;
    //                     l--;
    //                 }
    //             }
        
    //             return true;
    //         }
    //     };
        
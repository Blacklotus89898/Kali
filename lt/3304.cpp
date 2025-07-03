class Solution {
    public:
        char kthCharacter(int k) {
            string word = "a";
            while (word.size() < k) {
                int len = word.size();
                for (int i = 0; i < len; ++i) {
                    if (word[i] == 'z') {
                        word += 'a';
                    } else {
                        char c = word[i];
                        word += ++c;
                    }
                }
            }
    
            return word[k - 1];
        }
    };
class Solution
{
public:
    vector<int> findWordsContaining(vector<string> &words, char x)
    {
        vector<int> res;
        for (int i = 0; i < words.size(); ++i)
        {
            for (const char c : words[i])
            {
                if (c == x)
                {
                    res.push_back(i);
                    break;
                }
            }
        }

        return res;
    }
};

/*
#include <vector>
#include <string>
#include <algorithm> // For std::find

class Solution {
public:
std::vector<int> findWordsContaining(std::vector<std::string>& words, char x) {
    std::vector<int> res;
    for (int i = 0; i < words.size(); ++i) {
        if (std::find(words[i].begin(), words[i].end(), x) != words[i].end()) {
            res.push_back(i);
        }
    }
    return res;
}
};


*/
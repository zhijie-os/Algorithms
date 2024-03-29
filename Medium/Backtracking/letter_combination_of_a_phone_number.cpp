#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    // O(n) space, O(n) time
    vector<string> letterCombinations(string digits)
    {
        if(digits.empty())
            return {};
            
        vector<string> res;
        string charmap[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        res.push_back("");

        for (int i = 0; i < digits.size(); i++)
        {
            vector<string> tempres;
            string chars = charmap[digits[i] - '0'];
            for (int c = 0; c < chars.size(); c++)
                for (int j = 0; j < res.size(); j++)
                    tempres.push_back(res[j] + chars[c]);
            res = tempres;
        }
        return res;
    }
};
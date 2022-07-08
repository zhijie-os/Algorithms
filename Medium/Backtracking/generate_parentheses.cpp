#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        addingpar(res, "", n, 0);
        return res;
    }

    // n: number of left parentheses needed
    // m: number of right parentheses needed to make valid
    void addingpar(vector<string> &v, string str, int n, int m){
        if(n==0 && m==0)
        {
            // base case
            v.push_back(str);
            return;
        }
        if(m > 0)
            // close a left parenthesis
            addingpar(v, str+")", n, m-1);
        if(n > 0) 
            // begin a left parenthesis
            addingpar(v, str+"(", n-1, m+1);
    }
};
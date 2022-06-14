#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int index=0;

        bool flag=true;

        for(int i=0;i<strs[0].size();i++)
        {
            char c=strs[0][i];
            for(int j=1;j<strs.size();j++)
            {
                if(c!=strs[j][i])
                {
                    return strs[0].substr(0,i);
                }
            }
        }

        return strs[0];

    }
};
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        bool flag;

        for(int i=0; i<n-m+1;i++)
        {
            flag = true;
            for(int j=0;j<m;j++)
            {
                if(haystack[i+j]!=needle[j])
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            return i;
        }

        return -1;
    }
};


// Knuth-Morris-Pratt(KMP) Pattern Matching


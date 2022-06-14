#include <string>
#include <vector>

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

class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int m = haystack.size(), n = needle.size();

        if(needle.empty())
        {
            return 0;
        }

        vector<int> lps = kmpProcess(needle);
        

        for(int i=0, j=0; i<m;)
        {
            if(haystack[i]==needle[j])
            {
                    if(j==n-1)
                    {
                        return i-n+1;
                    }
                    else 
                    {
                        i++;
                        j++;
                    }
            }
            else{
                // does not match any
                if(j==0)
                {
                    i++;
                }
                else 
                {
                    // j is the place that the prefix ends
                    j = lps[j-1];
                }

            }

        }

        return -1;
    }

    vector<int> kmpProcess(string needle)
    {
        
        int n = needle.size();
        vector<int> lps(n,0);
        
        for(int i=1, len=0; i<n;)
        {
            if(needle[i] == needle[len])
            {
                // at needle[i], the length of suffix that is prefix is ++len
                lps[i++] = ++len;
            }
            else if(len)    
            {
                // reset to the beginning
                len = lps[len-1];
            }
            else 
            {
                // discontinuity
                lps[i++]=0;
            }
        }
        return lps;
    }
};
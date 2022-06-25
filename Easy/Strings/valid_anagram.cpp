#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
        {
            return false;
        }

        unordered_map<char,int> lookup;
        for(int i=0;i<s.size();i++)
        {
            if(lookup.find(s[i])==lookup.end())
            {
                lookup[s[i]]=1;
            }
            else 
            {
                lookup[s[i]]+=1;
            }
        }

        for(int i=0;i<t.size();i++)
        {
            if(lookup.find(t[i])==lookup.end())
            {
                return false;
            }
            else 
            {
                lookup[t[i]]-=1;
                if(lookup[t[i]]<0)
                {
                    return false;
                }
            }
        }
        
        return true;
    }
};
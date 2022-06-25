#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
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

        for(int i=0;i<s.size();i++)
        {
            if(lookup[s[i]]==1)
            {
                return i;
            }
        }
        return -1;
    }
};
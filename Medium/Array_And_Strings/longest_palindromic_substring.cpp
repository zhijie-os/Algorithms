// well, I still remember this is a classic DP problem

#include <string>
#include <vector>

using namespace std;


// if s[i,j] is palindrome, then s[i-1,j+1] is palindrome
// if and only if s[i-1] == s[j+1] 


// s[i,i+1], s[i]=s[i+1]


// how long it will take to verifiy palidrome string?
// O(n)
// => O(n^3)

// dp brings the time complexity down to O(n^2)



class Solution {
public:
    string longestPalindrome(string s) {
        // we are doing bottom up
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));
        
        for(int i=0; i<s.length(); i++)
        {
            dp[i][i] = true;
        }
    
        int start=0;
        int maxLength=1;

        for(int i=s.length()-1; i>=0; i--)
        {
            for(int j=i+1; j<s.length(); j++)
            {
                if(s[i]==s[j])
                {
                    if(dp[i][j] = dp[i+1][j-1]||j-i==1)
                    {
                        dp[i][j] = true;
                        if(j-i+1>maxLength)
                        {
                            start = i;
                            maxLength = j-i+1;
                        }
                    }
                }
            }
        }

        return s.substr(start, maxLength);
    
    }
}; 

#include <vector>

class Solution {
public:
    // bottom up, dp[i] = how many ways that I can get to ith stair
    // dp[i] = dp[i-1]+dp[i-2]
    int climbStairs(int n) {
        std::vector<int> dp(n+1);
        // set base case
        dp[0]=1;
        dp[1]=1;

        for(int i=2; i<n+1; i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }

        return dp[n];
    }
};

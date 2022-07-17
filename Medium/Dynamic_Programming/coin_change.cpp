#include <vector>
#include <iostream>
#include <limits>
using namespace std;

class Solution {
public:
    // DP[i] = DP[i-coin] + 1
    int coinChange(vector<int>& coins, int amount) {
        int Max = amount + 1;
        vector<int> dp(amount + 1, Max);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }

        return dp[amount]>amount?-1:dp[amount];
    }
};  


#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // dp[i] = what is maximum profit if sells on day i
    // dp[i+1] = max(dp[i]+price[i+1]-price[i],0)
    int maxProfit(vector<int>& prices) {
        vector<int> dp(prices.size());
        // base case
        dp[0]=0;

        for(int i=1; i<prices.size(); i++)
        {
            dp[i]=max(dp[i-1]+prices[i]-prices[i-1],0);
        }
		
		int max=0;

		for(auto e:dp)
		{
			if(e>max)
				max=e;
		}

		return max;
    }
};

#include <vector>
#include <algorithm>

using namespace std;

// what is a brute force solution?
// O(n^2) with filter
// dp should do it in O(n)
// the subproblem: the maximum amount of money that I can steal, either steal i-th house or not
// dp[i] = max(dp[i-2]+nums[i],dp[i-1])
class Solution {
public:
    int rob(vector<int>& nums) {
		if(nums.size()==1)
		{
			return nums[0];
		}
        vector<int> dp(nums.size());

        dp[0]=nums[0];
        dp[1]=nums[0]>nums[1]?nums[0]:nums[1];


        for(int i=2; i<nums.size(); i++)
        {
            dp[i] = max(dp[i-2]+nums[i],dp[i-1]);
        }

        // will be overwritten
        int profit=0;
        for(auto e:dp)
        {
            if(e>profit)
                profit = e;
        }

        return profit;
    }
};

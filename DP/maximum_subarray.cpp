#include <vector>
#include <algorithm>

using namespace std;



// brute force = O(n^2)
// thus, dp should only take O(n)
// the subproblem: dp[i] = the sum of the subarray that ends with i-th element
// dp[i] = max(dp[i-1]+nums[i], nums[i])
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());

        dp[0] = nums[0];

		for(int i=1; i<nums.size(); i++)
        {
            dp[i] = max(dp[i-1]+nums[i],nums[i]);
        }

        int sum=dp[0];

        for(auto e:dp)
        {
            if(e>sum)
            {
                sum = e;
            }
        }

        return sum;
    }
};

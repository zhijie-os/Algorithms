class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
			// dp[i] is the longest increasing subsequence of nums[0..i] which has num[i] as the end of the subsequence
			int n = nums.size();
			vector<int> dp(n,1);
			int max = dp[0];
			for(int i=0; i<n; i++){
				for(int j=0; j<i; j++){
					if(nums[i]>nums[j])
						if(1+dp[j]>dp[i])
							dp[i] = dp[j]+1;
					if(dp[i]>max)
						max = dp[i];
				}
			}
			return max;
    }
};

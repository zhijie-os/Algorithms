#include <iostream>
#include <vector>
#include <limits>

using namespace std;




// dynamic programming 
// subproblem: the maximum subarray end at index i
// DP(i) = max(DP(i-1)+A[i], A[i])
// translation: if the optimal solution that ends with A[i],
// it is either contigous with the optimal solution ends with A[i-1], or it is itself


class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        std::vector<int> dp(nums.size());
        
        // initialize DP[0] to start
        dp[0] = nums[0];
        int max = dp[0];

        for(int i=1; i<nums.size(); i++)
        {
            // translat
            if(dp[i-1]+nums[i]>nums[i])
            {
                dp[i]=dp[i-1]+nums[i];
            }
            else 
            {
                dp[i]=nums[i];
            }
            
            if(dp[i]>max)
            {
                max=dp[i];
            }
        }

        return max;

    }

};



// divide&conquer, this makes the most sense to me
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        return maxSubArrayHelper(nums, 0, nums.size()-1);
    }

    int maxSubArrayHelper(std::vector<int> &nums, int low, int high)
    {
        // base case: when there is only one
        if(low==high)
        {
            return nums[low];
        }

        int mid = (low+high)/2;
        
        // T(n) = 2T(n/2).....

        // divide <-> subproblems: the maxSubArray on left and on right
        int maxLeft = maxSubArrayHelper(nums,low,mid);
        int maxRight = maxSubArrayHelper(nums,mid+1,high);


        // T(n) = O(n).....
        // max sub array is cross the mid
        int crossLeft = std::numeric_limits<int>::min();
        int sum = 0;
        for(int i=mid; i>= low; i--){
            sum += nums[i];
            if(sum>crossLeft)
            {
                crossLeft = sum;
            }
        }

        int crossRight = std::numeric_limits<int>::min();
        sum = 0;
        for(int i=mid+1; i<= high; i++){
            sum += nums[i];
            if(sum>crossRight)
            {
                crossRight = sum;
            }
        }


        int max;
        // merge = O(1)
        if(maxLeft>maxRight)
        {
            max = maxLeft;
        }
        else 
        {
            max = maxRight;
        }

        if(max < crossLeft+crossRight)
        {
            max = crossLeft + crossRight;
        }

        return max;
    }
};

#include <iostream>
#include <vector>
#include <limits>

using namespace std;



// Dynamic Programming: DP_MAX(i) = Max(DP_MAX[i-1]*A[i], DP_MIN[i-1]*A[i],A[i])
// Dynamic Programming: DP_MIN(i) = Min(DP_MAX[i-1]*A[i], DP_MIN[i-1]*A[i],A[i])


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        std::vector<int> dp_max(nums.size());
        std::vector<int> dp_min(nums.size());   

        dp_max[0] = nums[0];
        dp_min[0] = nums[0];
        int max = dp_max[0];


        for(int i=1; i<nums.size(); i++){
            if(dp_max[i-1]*nums[i]> dp_min[i-1]*nums[i])
            {
                dp_max[i] = dp_max[i-1]*nums[i];
            }
            else 
            {
                dp_max[i] = dp_min[i-1]*nums[i];
            }

            if(nums[i]>dp_max[i])
            {
                dp_max[i] = nums[i];
            }


            if(dp_max[i-1]*nums[i]< dp_min[i-1]*nums[i])
            {
                dp_min[i] = dp_max[i-1]*nums[i];
            }
            else 
            {
                dp_min[i] = dp_min[i-1]*nums[i];
            }

            if(nums[i] < dp_min[i])
            {
                dp_min[i] = nums[i];
            }


            if(dp_max[i]>max)
            {
                max = dp_max[i];
            }


        }

        return max;
    }
};
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int totals=0;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                totals++;
            }
            else 
            {
                // n zeros have been counted, shift n place left
                nums[i-totals]=nums[i];
            }
        }

        for(int i=1;i<=totals;i++)
        {
            nums[nums.size()-i]=0;
        }

    }
};
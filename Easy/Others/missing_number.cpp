class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing_one=0;

        for(int i=0; i<nums.size(); ++i)
        {
            missing_one+=(i+1);
            missing_one-=nums[i];
        }

        return missing_one;
    }
};

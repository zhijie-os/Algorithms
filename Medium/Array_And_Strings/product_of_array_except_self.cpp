class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int nonZeroProduct=1;
        int zeroCount = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]!=0)
                nonZeroProduct *= nums[i];
            else
                zeroCount++;
        }

        vector<int> result(nums.size());


        for(int i=0; i<nums.size(); i++)
        {
            if(zeroCount>1)
            {
                result[i]=0;
            }
            else if(zeroCount==1)
            {
                if(nums[i]==0)
                    result[i] = nonZeroProduct;
                else
                    result[i] = 0;
            }
            else
            {
                result[i] = nonZeroProduct / nums[i];
            }
        }
		return result;
    }
};

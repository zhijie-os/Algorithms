class Solution {
public:
    int findDuplicate(vector<int>& nums) {
		for(int i=0;i<nums.size();++i)
		{
			while(nums[i]>0&&nums[i]<=nums.size()
					&&nums[nums[i]-1]!=nums[i])
			{
				// suppose nums[i] = 1
				// should be placed in index 0
				int temp = nums[nums[i]-1];
				nums[nums[i]-1] = nums[i];
				nums[i] = temp;
			}
		}

		for(int i=1;i<=nums.size();++i)
		{
			if(nums[i-1]!=i)
			{
				return nums[i-1];
			}
		}

		return -1;
    }
};

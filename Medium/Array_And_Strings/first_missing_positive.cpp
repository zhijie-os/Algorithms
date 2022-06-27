#include <limits>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
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

		for(int i=0;i<nums.size();i++)
		{
			if(nums[i]!=i+1)
			{
				return i+1;
			}
		}

		return nums.size()+1;
	}
};

int main()
{
	Solution s;
	vector<int> k={3,4,-1,1};
	s.firstMissingPositive(k);
}

class Soluton {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		std::vector<vector<int>> result;
		std::sort(nums.begin(), nums.end());


		for(int i=0; i < nums.size(); i++)
		{
			// this would be the targeted value for the sum of the other two indexes
			int target = -nums[i];

			// i < start < end
			int start = i+1;
			int end = nums.size()-1;


			while(start<end)
			{
				// if the sum is too small, increase the start
				if(nums[start]+nums[end] < target)
				{
					start++;
				}// if the sum is too large, decrease the end
				else if(nums[start]+nums[end] > target)
				{
					end--;
				}
				else
				{
					// find a solution, push
					vector<int> toPush = {nums[i], nums[start], nums[end]};
					result.push_back(toPush);
					// move forward to make sure that a second solution wont have the
					// same nums[start], since if nums[i] and nums[start] determines
					// an unique nums[end]
					while(start<end && nums[start]==toPush[1])
					{
						start++;
					}

					// similar ideas
					while(end>start && nums[end]==toPush[2])
					{
						end--;
					}
				}
			}

			// move forward to avoid duplicates.
			while(i+1<nums.size()&&nums[i]==nums[i+1])
			{
				i++;
			}
		}
		return result;
		
	}
};

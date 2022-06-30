class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
		// copy everything in the vector 
        unordered_set<int> present(nums.begin(),nums.end());
		int maxConsecutive = 0;
		for(auto num:nums)
		{
			// if the num is erased, do not consider further
			if(present.find(num)==present.end())
				continue;

			// erase from the set
			int count=1;
			present.erase(num);
			int upper=num+1;
			int lower=num-1;
			while(present.find(upper)!=present.end())
			{
				present.erase(upper);
				count++;
				upper++;
			}

			while(present.find(lower)!=present.end())
			{
				present.erase(lower);
				count++;
				lower--;
			}

			if(count > maxConsecutive)
			{
				maxConsecutive = count;
			}
		}
		return maxConsecutive;
    }
};

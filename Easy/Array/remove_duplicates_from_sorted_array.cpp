// non-decreasing order
// remove duplicatess
// remove inplace

#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // offset == the number of duplicates have seen
        // shift left 

        int last=nums[0], current, offset=0;
        for(int i=1; i < nums.size(); i++)
        {
            current = nums[i];
            if(last==current)
            {
                offset++;
            }
            last = current;
            nums[i-offset] = nums[i];
        }

        return nums.size()-offset;
    }
};
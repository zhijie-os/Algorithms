#include <vector>
using namespace std;


class Solution {
public:
    // counting sort
    void sortColors(vector<int>& nums) {
        int reds = 0;
        int whites = 0;
        int blues = 0; 

        for(auto num : nums)
        {
            if(num==0)
                reds++;
            if(num==1)
                whites++;
            if(num==2)
                blues++;
        }

        for(int i=0;i<reds;i++)
        {
            nums[i] = 0;
        }

        for(int i=reds;i<reds+whites;i++)
        {
            nums[i] = 1;
        }

        for(int i=reds+whites;i<nums.size();i++)
        {
            nums[i] = 2;
        }
    }
};
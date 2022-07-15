#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        // walk from the end of the list
        int lastGoodPosition = nums.size()-1;

        for(int i=nums.size()-1; i>=0; i--){
            if(i+nums[i]>=lastGoodPosition){
                lastGoodPosition = i;
            }
        }   

        return lastGoodPosition==0;
    }
};
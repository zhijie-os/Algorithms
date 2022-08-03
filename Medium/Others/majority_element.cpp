#include <vector>
using namespace std;


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = nums[0], count = 1;
        for(int i=1; i<nums.size(); i++){
            if(count==0){
                // if the count is zero, then half of countered elements are different
                // might not be the majority
                count++;
                // pick an new element as majority
                major=nums[i];
            }
            else if(major==nums[i]){
                count++;
            }
            else{
                count--;
            }
        }
        
        return major;
    }
};
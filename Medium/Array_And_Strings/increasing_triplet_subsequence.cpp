#include <limits>
#include <vector>
using namespace std;


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int num1=numeric_limits<int>::max(),
        num2=numeric_limits<int>::max();

        for(int i=0; i < nums.size(); i++)
        {
            if(nums[i] <= num1) // num1 will be the smallest number seeing so far
            {
                num1 = nums[i];
            }
            else if(nums[i] <= num2) // only nums[i] > num1, then consider number 2
            {
                num2 = nums[i];
            }
            else // the number is greater than num1 and num2, then satifisied
            {
                return true;
            }
        }

        return false;
    }
};
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int idx1 = lower_bound(nums, target);
        // even if the number does not exit in the nums, the right handside would slide to left until the end of target range
        int idx2 = lower_bound(nums, target+1)-1;
        
        if (idx1 < nums.size() && nums[idx1] == target)
            return {idx1, idx2};
        else
            return {-1, -1};
    }

    int lower_bound(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;

        while (l <= r) {

            int mid = (r-l)/2+l;
            
            if (nums[mid] < target)
                l = mid+1;
            else // keep sliding to left
                r = mid-1;
        }

        return l;
    }
};
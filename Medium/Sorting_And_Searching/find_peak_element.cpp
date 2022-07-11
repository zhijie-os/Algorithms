#include <vector>

using namespace std;


// O(n) trival solution

// O(lgn) is feasible
class Solution {
public:

    
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1) 
            return 0;

        return findPeakElementDaemon(nums, 0, nums.size()-1);
    }

    int findPeakElementDaemon(vector<int>& nums, int left, int right) {
       
        if(left==right)
            return left; // base case

        // mid1 never equals mid2
        int mid1 = (left+right)/2;
        int mid2 = mid1+1;


        if(nums[mid1] > nums[mid2]) // find in left half
            return findPeakElementDaemon(nums, left, mid1);
        else // find in right half
            return findPeakElementDaemon(nums, mid2, right);

        return -1;
    }

};

int main()
{
    Solution s;
    vector<int> k={2,1};
    s.findPeakElement(k);
}

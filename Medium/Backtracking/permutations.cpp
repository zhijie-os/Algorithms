#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;


        permuteRecursive(nums, 0, result);
        return result;
    }


    void permuteRecursive(vector<int> &nums, int begin, vector<vector<int>> &result)
    {
        if(begin >= nums.size())
        {
            // one permutation instance here
            result.push_back(nums);
            return;
        }

        for(int i=begin; i<nums.size(); i++) // next iteration = A is fixed at wherer it is 
        {
            swap(nums[begin],nums[i]);
            // for the further permutation, every elements before begin is "fixed"
            permuteRecursive(nums, begin+1, result);
            swap(nums[begin],nums[i]);
        }
    }
};
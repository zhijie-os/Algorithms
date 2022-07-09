#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        // sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        vector<int> temp; 

        backtrack(nums, result, temp, 0);
        return result;
    }

    void backtrack(vector<int>& nums, vector<vector<int>> &result, vector<int> &temp, int index)
    {
        result.push_back(temp);
        for(int i=index; i < nums.size(); i++)
        {
            // either include or not
            temp.push_back(nums[i]); // include for further
            backtrack(nums,result,temp,i+1);
            temp.pop_back(); // not include for further
        }
    }

    
};
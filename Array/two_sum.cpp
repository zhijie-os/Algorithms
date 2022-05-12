#include <iostream>
#include <vector>

#include <unordered_map>

using namespace std;


/**
 * naive approach: O(n^2) 
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int length = nums.size();
        for(int i=0;i<length;i++)
        {
            for(int j=i+1;j<length;j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    return {i,j};
                }
            }
        }
        return {};
    }
};


/**
 * 
 * if it is already in the map, O(1) to lookup 
 * if not in the map, O(1) to add it into the map
 * 
 * say num[i]+num[j] == target:
 *      when iterate to element i, num[j] is not in the map; continue
 *      when iterate to element j, num[i] must be in the map already
 * 
 * Total time complexity = O(n)
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> map;

        for(int i=0;i<nums.size();i++)
        {
            if(map.find(target-nums[i])!=map.end())
            {
                return {i,map[target-nums[i]]};
            }
            else 
            {
                map[nums[i]]=i;
            }
        }

        return {};
    }
};


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/**
 * O(n) using unordered_map
 */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_map<int,int> map;

        for(auto e:nums)
        {
            if(map.find(e) != map.end())
            {
                return true;
            }
            else 
            {
                map[e] = 1;
            }
        }
        return false;
    }
};


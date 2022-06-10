#include <unordered_map>
#include <vector>

using namespace std;


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> count;

        for(int i=0;i <nums.size();i++)
        {
            if(count.find(nums[i])==count.end())
            {
                count[nums[i]] = 1;
            }  
            else 
            {
                count[nums[i]] += 1;
            }
        }

        for(auto& it:count){
            if(it.second==1)
            {
                return it.first;
            }
        }

        return -1;

    }
};


// one path
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // A ^ A = 0 and A ^ B ^ A = B.

        int result=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            result ^= nums[i];
        }

        return result;

    }
};
#include <vector>
#include <string>
using namespace std;


class Solution {
public:  
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ranges;

        int64_t pre = static_cast<int64_t>(lower) - 1, cur = 0;

        for(int64_t i = 0; i <= nums.size(); ++i)
        {
            if(i==nums.size())
            {
                cur = static_cast<int64_t>(upper) + 1;
            }
            else{ // cur points to the current number
                cur = nums[i];
            }

            if(cur - pre>=2)
            {
                ranges.push_back(getRange(pre+1, cur-1));
            }
            
            pre = cur;
        }

        return ranges;
    }

private:
    string getRange(const int lower, const int upper) {
        if (lower == upper) {
            return to_string(lower);
        } else {
            return to_string(lower) + "->" + to_string(upper);
        }
    }
};
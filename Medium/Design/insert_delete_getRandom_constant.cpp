#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstdlib>

using namespace std;

class RandomizedSet
{
    // amortized O(1)
private:
    // num -> index in the vector
    unordered_map<int, int> occur;
    vector<int> nums;

public:
    RandomizedSet()
    {
    }

    bool insert(int val)
    {

        if (occur.find(val) != occur.end())
        {
            return false;
        }

        // if not presented, put into the vector, record the index
        occur[val] = nums.size();
        nums.push_back(val);
        return true;
    }

    bool remove(int val)
    {
        // erase() is O(n), need to fill in the gap that created
        // pop_back() is O(1), only decrease the size.
        // Should overwrite the value for security reason in practice.

        if (occur.find(val) == occur.end())
        {
            return false;
        }

        // update the index
        occur[nums.back()] = occur[val];

        // swap the element to the end of the vector
        swap(nums[occur[val]], nums[nums.size()-1]);
        // pop out the num
        nums.pop_back();
        // delete the index in occur
        occur.erase(val);
        return true;
    }

    int getRandom()
    {
        // random in range of 0 and nums.size()-1
        return nums[rand()%nums.size()];
    }
};
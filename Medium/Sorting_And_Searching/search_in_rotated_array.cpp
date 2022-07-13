#include <vector>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;

        // find the smallest element => pivot point
        while (low < high)
        {
            int mid = (low + high) / 2;

            if (nums[mid] > nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        // find the point that is the pivot
        int pivot = low;

        low = 0, high = nums.size() - 1;
        // find the element
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int realmid = (mid + pivot) % nums.size();

            if (nums[realmid] == target)
            {
                return realmid;
            }

            if (nums[realmid] < target)
            {
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }

        return -1;
    }
};
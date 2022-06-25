#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int num_of_zero = 0;
        int non_zero_product = 1;

        for (auto e : nums)
        {
            if (e != 0)
                non_zero_product *= e;
            else
                num_of_zero++;
        }

        std::vector<int> result(nums.size(), 0);

        // if the number of zeros is greater than 1, the result would simply be zero
        if (num_of_zero < 2)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                // if there is a zero, and current pointing number is not zero, the product is zero
                if (nums[i] != 0 && num_of_zero > 0)
                    result[i] = 0;
                else if (nums[i] == 0)  // if the current number is 0, then product is the sum of non zeros
                    result[i] = non_zero_product;
                else // if there is no zero at all
                    result[i] = non_zero_product / nums[i];
            }
        }

        return result;
    }
};
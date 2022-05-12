#include <vector>

using namespace std;

#include <limits>

/**
 * brutal solution: O(n^2)
 */

/**
 * say we have a buy 'low', and sell 'high'; the current profit is 'high' - 'low'
 * how can we increase profit? 
 *      1. a new 'low', and expect future high
 *      2. a new 'high' such that 
 * 
 *  running time = O(n)
 */

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {

        int low = std::numeric_limits<int>::max();

        int profit = 0;

        for(int i=0; i<prices.size();i++)
        {
            if(prices[i]<low)
            {
                low = prices[i];
            }

            if(prices[i]-low > profit)
            {
                profit = prices[i]-low;
            }
        }

        return profit;
    }
};
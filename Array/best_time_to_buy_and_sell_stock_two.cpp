#include <vector>
#include <limits>

using namespace std;

// this is a peak finding question
// how to maximum profit?
// for every chance that can earn profit, do it
// ie, sum of from consecutive local min to local max

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // the first number is either local min or local max
        // lastMin is ought to be set as a higher number than the next local min
        int lastMin = prices[0];
        int profit = 0;
        for(int i=1;i<prices.size();i++)
        {
            // local max
            if(prices[i] > prices[i-1] && 
                (prices.size()==i+1||
                prices[i] >= prices[i+1]) ){
              
                profit += prices[i]-lastMin;
            }
            else if(prices[i] <= prices[i-1] &&
                (prices.size()==i+1||
                prices[i] <= prices[i+1])) // local min
            {
                lastMin = prices[i];
            }
        }

        return profit;
    }
};
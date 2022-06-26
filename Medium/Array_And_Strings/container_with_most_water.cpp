#include <vector>

using namespace std;


class Solution {
public:

    // two pointer greedy algorithm
    // well.... 
    // greedy is greedy, try it out. If it works, it works.
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size()-1;

        int max = 0;

        // O(n)
        while( start < end )
        {
            // calculate area
            int area = min(height[start],height[end])*(end-start);
            if(area > max)
            {
                max = area;
            }

            if(min(height[start],height[end])==height[start])
            {
                start++;
            }
            else 
            {
                end--;
            }
        }

        return max;
    }
};



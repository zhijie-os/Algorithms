#include <vector>
#include <algorithm>

using namespace std;

bool mysort(vector<int>& a, vector<int>& b){
    return a[0] < b[0];
}


// sorting => O(nlgn)
class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), mysort);
        
        vector<vector<int>> result; 
        result.push_back(intervals[0]);

        vector<int> prev;
        vector<int> curr;

        for(int i=1; i < intervals.size(); i++){
            prev = result.back();   
            curr = intervals[i];

            if(curr[1] >= prev[1]){
                continue;
            }
            else if(curr[0] <= prev[1]){
                prev[1] = curr[1]; // extend the range
                result.pop_back();
                result.push_back(prev);
            }
            else{
                result.push_back(curr);
            }
        }

        return result;
    }
};
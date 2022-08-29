#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int>occurrence;
        int count = 0; // count is the maximum occurrence
        for(auto t : tasks) {
            occurrence[t]++;
            count = max(count, occurrence[t]);
        }

        int ans = (count-1)*(n+1);
        for(auto e: occurrence) {
            if(e.second == count ){
                ans++;
            }
        }

        return max((int)tasks.size(), ans);
    }
};

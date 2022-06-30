#include <vector>
#include <unordered_map>

/**
 * @brief Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:
 * 0 <= i, j, k, l < n
 * nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
 * 
 */

using namespace std;


// brute force = O(n^4)


// I can do O(n^3) by storing an array into a hashtable


// What if I use an unordered_map<int, unordered_map<int,int>> ?
// creating the unordered_map takes O(n^2)

// another O(n^2) to loop through the other two lists

// space = O(n^2)

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        // int -> int 
        // sum of a particular int in nums1 + sum of a particular int in nums2 -> occurrence
        unordered_map<int, int> map;        

        for(int i:nums1)
        {
            for(int j:nums2)
            {
                map[i+j]++;
            }
        }

        int result = 0;

        for(int i:nums3)
        {
            for(int j:nums4)
            {
                result += map[-(i+j)];
            }
        }

        return result;

    }
};
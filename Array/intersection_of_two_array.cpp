#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// I honestly have no idea what the question is asking for

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> occurrence;

        for(int i=0;i<nums1.size();i++)
        {
            if(occurrence.find(nums1[i]) == occurrence.end())
            {
                occurrence[nums1[i]] = 1;
            }
            else 
            {
                occurrence[nums1[i]] += 1;
            }
        }

        vector<int> result;

        
        for(int i=0;i<nums2.size();i++)
        {
            if(occurrence.find(nums2[i]) == occurrence.end())
            {
                if(occurrence[nums2[i]]>0)
                {
                    occurrence[nums2[i]]--;
                    result.push_back(nums2[i]);
                }
            }
            
        }


        return result;
    }
};


// sort first
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        // two finger algorithm

        int i=0, j=0;

        vector<int> result;
        while(i<nums1.size()&&j<nums2.size())
        {
            if(nums1[i]==nums2[j])
            {
                result.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i] < nums2[j] )
            {
                i++;
            }
            else
            {
                j++;
            }

            
        }
        return result;
    }

};
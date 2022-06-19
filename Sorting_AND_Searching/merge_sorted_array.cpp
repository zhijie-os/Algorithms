
/**
 *You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
 */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.resize(m+n);

        // merge backwards
        int i=m-1;
        int j=n-1;
        int k=m+n-1;

        // since we are merging into nums1
        // we have to make sure that we merged everything that is in nums2
        while(j>=0)
        {
            if(i>=0&&nums1[i]>nums2[j])
			{
                nums1[k] = nums1[i];
                i--;
            }
            else
            {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
    }
};

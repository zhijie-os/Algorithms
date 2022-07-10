// kth -> partition


// Given an integer array nums and an integer k, 
// return the kth largest element in the array.

// Note that it is the kth largest element in the 
// sorted order, not the kth distinct element.


#include <vector>
#include <algorithm>
#include <random>
using namespace std;


// sorting = O(nlogn)

// partition = O(n) expected, worst case = O(n^2)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        quickSelect(nums, 0, n-1, n-k);
        return nums[k];
    }

    void quickSelect(vector<int>& nums, int left, int right, int k)
    {
        if(left==right)
            return;
        // get rand pivot index
        int pivot_index = left + rand() % (right - left + 1);

         // find the pivot position in a sorted list
        pivot_index = partition(nums, left, right, pivot_index);
        if(pivot_index < k)
        {
            quickSelect(nums,pivot_index+1, right, k);
        }
        else if(pivot_index > k){
            quickSelect(nums, left, pivot_index-1, k);
        }
    }

    int partition(vector<int>& nums, int left, int right, int pivot_index)
    {
        int store_index = left;
        int pivot_value = nums[pivot_index];

        swap(nums[pivot_index], nums[right]);

        for(int i=left; i<=right;i++)
        {
            // put smaller one before store_index
            if(nums[i]<pivot_value)
            {
                swap(nums[i], nums[store_index]);
                store_index++;
            }
        }
        
        swap(nums[store_index], nums[right]);

        return store_index;
    }
    

};

int main()
{
    Solution s;
    vector<int> nums =  {3,2,1,5,6,4};
    s.findKthLargest(nums, 2);
}
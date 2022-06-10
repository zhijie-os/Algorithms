#include <vector>

using namespace std;


// O(n) space O(n) time
class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int wa = k%nums.size();
        vector<int> copied(nums);
        int j=0;

        for(int i=nums.size()-wa;i<nums.size();i++)
        {
            nums[j] = copied[i];
            j++;
        }

        for(int i=0;i<nums.size()-wa;i++)
        {
            nums[j] = copied[i];
            j++;
        }
    }
};

// O(1) space, O(n) time
// using three reverses
// three reverses rotate an array
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();

        reverse(nums, 0, nums.size()-1);
        reverse(nums, 0, k-1);
        reverse(nums,k, nums.size()-1);
    }

    void reverse(vector<int>& arr, int start, int end)
    {
        int temp;
        while(start<end)
        {
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }
};

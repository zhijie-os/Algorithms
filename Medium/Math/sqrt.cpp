#include <limits>
class Solution {
public:

    // if there is a sqrt of the number, we can use binary search to find that number
    // the difference between ordinary binary search and mySqrt 
    // is that we are going ot use num*num == target instead of num==target
    int mySqrt(int x) {
        if(x==0)
            return 0;

        int left = 1, right = x;


        while(true){
            int mid = left+(right-left)/2;
            if(mid > x/mid){
                right = mid - 1;
            }
            else{
                if(mid+1>x/(mid+1)){
                    return mid;
                }
                left = mid + 1;
            }
        }

        return -1;
    }
};
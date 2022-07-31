#include <algorithm>

class Solution {
public:
    /*
        Idea: convert n into binary
        e.g: n = 9 = 2^3+2^0 = 0b1001

        x^9 = x^2^3 * x^2^0 * 1

        everytime, when counter a 1 in binary, we simply mutiply the result by x^2^i
        we keep the x^2^i in a variable and update the variable in each iteration

        running time is bounded to the length of the binary representation of the n
    */

    double myPow(double x, int n) {
        double result = 1;
        int absN = abs(n);
        
        while(absN>0){
            // if there is a 1 bit
            if(absN&1!=0){
                result *= x;
            }
            // shift one bit right
            absN >>= 1;
            // update to x^2^i, x^2^0 => x^2^1 => x^2^2 ...
            x*=x;
        }
        
        return n>0 ? result : 1/result;
    }


    // too slow: O(n) 
    // double myPow(double x, int n) {
    //     bool flip = n < 0;
    //     n = abs(n);

    //     double result = 1;
    //     for(int i=0;i<n;i++){
    //         result *= x;
    //     }

    //     return flip ? 1/result : result;
    // }
};
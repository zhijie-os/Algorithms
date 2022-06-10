#include <vector>

using namespace std;

// You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

// Increment the large integer by one and return the resulting array of digits.


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1;
        int temp;

        for(int i=digits.size()-1;i>0;i--)
        {
            temp = digits[i]+carry;
            if(temp>=10)
            {
                temp%=10;
                carry=1;
            }
            else 
            {
                carry=0;   
            }
            digits[i]=temp;


            // as long as there is no carry, the addition is done
            if(carry==0)
            {
                return digits;
            }
        }

        temp = digits[0]+carry;
        
        // if there is carry, insert in the beginning
        if(temp>=10)
        {
            temp%=10;
            digits[0] = temp;
            digits.insert(digits.begin(),1);
        }
        else 
        {
            digits[0] = temp;
        }
        return digits;
    }
};
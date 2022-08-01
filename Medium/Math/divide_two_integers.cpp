#include <limits>
#include <algorithm>
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == std::numeric_limits<int>::min()&&divisor==-1){
            return std::numeric_limits<int>::max();
        }

        long dvd = abs(dividend), dvs = abs(divisor);
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        long result = 0;
        while(dvd >= dvs){
            long temp = dvs, shift = 1;
            while(temp << 1 <= dvd){
                temp <<= 1;
                shift <<= 1;
            }
            dvd -= temp;
            result += shift;
        }
        return sign*result;
    }

};
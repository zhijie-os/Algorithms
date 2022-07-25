

class Solution {
public:
    bool isHappy(int n) {

        int slow, fast;
        slow = fast = n;
        do {
            slow = digitSquareSum(slow);
            fast = digitSquareSum(fast);
            fast = digitSquareSum(fast);
        }while(slow != fast);
        if(slow==1)
            return 1;
        else 
            return 0;
    }

    int digitSquareSum(int n) {
        int sum=0, temp;
        while(n){
            temp = n%10;
            sum += temp*temp;
            n /= 10;
        }
        return sum;
    }
};
class Solution {
public:
    int hammingDistance(int x, int y) {
       int diff = 0, n = x^y; 
	   // bits are set to 1 if and only if x and y has different bits on that position

	   // count the 1s in n 
	   while(n!=0)
	   {
			diff++;
			n&=(n-1);
	   }

	   return diff;
    }
};

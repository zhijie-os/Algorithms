#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
		if(n<=1)
        {
            return 0;
        }
        
        vector<bool> primes(n-2,true);

        for(int i=2; i*i<n; i++)
        {
            if(primes[i-2])
            {
                for(int j=i*i; j<n; j+=i)
                {
                    primes[j-2]=false;
                }
            }
        }

        return count(primes.begin(),primes.end(),true);
	}
};

int main()
{
	Solution s;
	cout << s.countPrimes(10);
}

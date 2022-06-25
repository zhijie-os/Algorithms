#include <string>
#include <limits>
using namespace std;


class Solution {
public:
    int myAtoi(string s) {
        int result = 0;
        bool positive = true;
        int i=0;

        while(s[i]==' ')
        {
            i++;
        }

        if(s[i]=='+'||s[i]=='-')
        {
            positive = s[i++]=='+';
        }

        while(s[i]>='0'&&s[i]<='9')
        {
            if(result>numeric_limits<int>::max()/10||
                result==numeric_limits<int>::max()/10 &&
                s[i]-'0' > result==numeric_limits<int>::max()%10
            )
            {
                return positive?numeric_limits<int>::max():-numeric_limits<int>::max()-1;
            }
            result*=10;
            result+=s[i]-'0';
            i++;
        }

        return positive?result:-result;
    }
};
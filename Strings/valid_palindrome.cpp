#include <string>
#include <locale>         // std::locale, std::isalnum
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int head=0, tail=s.size()-1;
        while(head<tail)
        {
            if(!isalnum(s[head]))
            {
                head++;
                continue;
            }

            if(!isalnum(s[tail]))
            {
                tail--;
                continue;
            }

            if(tolower(s[head])!=tolower(s[tail]))
            {
                return false;
            }
            else 
            {
                head++;
                tail--;
            }
        }
        return true;
    }
};
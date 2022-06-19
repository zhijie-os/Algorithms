
// well, I think this is the same as  git bisect
class Solution {
public:
    int firstBadVersion(int n)
    {
        int start=1, end=n;

        while(start<end)
        {
            int mid = start+(end-start)/2;
            if(!isBadVersion(mid))
            {
                start = mid+1;
            }
            else
            {
                end = mid;
            }
        }

        return start;
    }



}

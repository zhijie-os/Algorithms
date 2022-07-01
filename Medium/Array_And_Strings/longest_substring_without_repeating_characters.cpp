clas Solution {
public:
    int lengthOfLongestSubstring(string s) {
		if(s.length()==0)
			return 0;

		unordered_map<char,int> occurrence;

		int start=0,end=0;
		occurrence[s[0]] = 1;
		int max=1;
		while(end<s.length()-1)
		{
			end++;
			occurrence[s[end]]+=1;
			while(occurrence[s[end]]>1){
				occurrence[s[start]]--;
				start++;
			}
			if(end-start+1>max)
				max = end-start+1;
		}
		return max;
    }
};

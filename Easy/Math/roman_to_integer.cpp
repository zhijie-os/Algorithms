class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int>table = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000},
        };

		int sum=0;
		for(int i=0;i<s.size()-1;i++)
		{
			if(table[s[i]]<table[s[i+1]]){
				sum-=table[s[i]];
			}
			else{
				sum+=table[s[i]];
			}
		}

		sum+=table[s.back()];
		return sum;
    };

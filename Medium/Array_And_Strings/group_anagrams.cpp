class Soluton {
public:
    vector<vector<string>> groupanagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> mp;
		
		// n times
		for(string s : strs)
		{
			string t=s;
			// average length of string, assume m
			// m*lgm
			sort(t.begin(), t.end());
			mp[t].push_back(s);
		} // time complexity, n*m*lgm

		// O(n)
		vector<vector<string>> anagrams;
		for(auto p:mp)
		{
			anagrams.push_back(p.second);
		}
		
		return anagrams;
    }

};

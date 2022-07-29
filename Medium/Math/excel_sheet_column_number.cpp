class Solution {
public:
    int titleToNumber(string columnTitle) {
		int result = 0;
		int pw = 0;
		for(int i=columnTitle.size()-1;i>=0; i--){
			result += (columnTitle[i]-'A'+1)*pow(26,pw);
			pw++;
		}       
		return result;
    }
};

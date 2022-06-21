class Solution {
public:
	vector<int> backup;
    Solution(vector<int>& nums) {
        backup = nums;
    }
    
    vector<int> reset() {
        return backup;
    }
    
    vector<int> shuffle() {
        vector<int> shuffled = backup;
		
		for(int i=0;i<backup.size();i++){
			int offset = rand()%(backup.size()-i);
			swap(shuffled[i],shuffled[i+offset]);
		}

		return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

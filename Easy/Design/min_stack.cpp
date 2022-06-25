class MinStack {
public:
	vector<int> values;
	vector<int> mins;

    MinStack() {
        
    }
    
    void push(int val) {
        values.push_back(val);
		if(mins.size()==0)
		{
			mins.push_back(val);
		}
		else
		{
			if(val<mins.back())
			{
				mins.push_back(val);
			}
			else
			{
				mins.push_back(mins.back());
			}
		}
    }
    
    void pop() {
        values.pop_back();
		mins.pop_back();
    }
    
    int top() {
        return values.back();
    }
    
    int getMin() {
        return mins.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

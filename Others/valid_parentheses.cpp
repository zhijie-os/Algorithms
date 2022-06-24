class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> canClose = {
            {')','('},
            {'}','{'},
            {']','['},
        };

        vector<char> stack;

        for(std::string::iterator it=s.begin(); it!=s.end(); ++it)
        {
            if(*it=='('||*it=='['||*it=='{')
            {
                stack.push_back(*it);
            }
            else if(*it==')'||*it=='}'||*it==']')
            {
                if(stack.empty()||stack.back()!=canClose[*it])
                {
					return false;                    
				}
                else
                {
					stack.pop_back();
                }
            }
        }


        return stack.size()==0;
    }
};


// for tree problem, only think what should happen in a single node


class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
        {
            return 0;
        }


        int left = maxDepth(root->left);
        int right = maxDepth(root->right);


        if(left<right)
        {
            return right+1;
        }
        else 
        {
            return left+1;
        }
        
    }
};
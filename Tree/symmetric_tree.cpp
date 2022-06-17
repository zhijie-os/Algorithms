/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)
        {
            return true;
        }

        TreeNode* leftTree;
        TreeNode* rightTree;

        vector<TreeNode*> stack;

        if(root->right)
        {
            if(!root->right){
                return false;
            }
            stack.push(root->left);
            stack.push(root->right);
        }
        else if(!root->right) 
        {
            return false;
        }


        while(!stack.empty())
        {
            if(stack.size()%2!=0)
            {
                return false;
            }
            rightTree = stack.back();
            stack.pop_back();

            leftTree = stack.back();
            stack.pop_back();

            if(left->val!=right->val)
            {
                return false;
            }

            if(!left->left)
            {
                if(!right->right)
                {
                    return false;
                }
                stack.push_back(leftTree->left);
            }


        }

        return leftTree||rightTree ? false:true;

    }
};


// recursion
class Solution {
public:
     bool isSymmetric(TreeNode* root) {
        return !root||isSymmetricHelper(root->left,root->right);
    }

    bool isSymmetricHelper(TreeNode* left, TreeNode*right)
    {
        if(!left||!right)
        {
            // need both null
            return left==right;
        }
        if(left->val!=right->val)
        {
            return false;
        }

        return isSymmetricHelper(left->left,right->right)&&isSymmetricHelper(left->right,right->left);
    }
}

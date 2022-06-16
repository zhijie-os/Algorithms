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

// For a BST,    x.left.val <= x.val <= x.right.val


std::vector<int> inorderTraversal(TreeNode *root)
{
    std::vector<int> list;
    if(!root)
    {
        return  list;
    }

    std::vector<TreeNode *> stack;
    
    while(root||!stack.empty())
    {
        while(root)
        {
            // descend to most left leaf
            stack.push_back(root);
            root = root->left;
        }

        root = stack.back();
        stack.pop_back();
        
        list.push_back(root->val);
        root = root->right;
    }

    return list; 
}

int kthSmallest(TreeNode root, int k)
{
    std::vector<TreeNode *> stack;

    while(root||!stack.empty())
    {
        while(root)
        {
            stack.push_back(root);
            root = root->left;
        }

        root = stack.back();
        stack.pop_back();

        if(--k==0)
        {
            break;
        }
        root = root->right;
    }
    return root->val;
}






class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root)
        {
            return true;
        }

        std::vector<TreeNode *> stack;
        TreeNode *pre = nullptr;


        while(root||!stack.empty())
        {
            while(root)
            {
                stack.push_back(root);
                root = root->left;
            }

            root = stack.back();
            stack.pop_back();

            // the inorder traversal of the BST should be ascendent
            // we just keep checking if the previous node is smaller or equal than the current one
            if(pre && root->val <= pre->val)
            {
                return false;
            }

            pre = root;
            root = root->right;
        }
        return true;
    }
};
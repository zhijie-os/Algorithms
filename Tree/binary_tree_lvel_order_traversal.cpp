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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
        {
            return {};
        }


        vector<vector<int>> result;
        vector<int> current;
        queue<TreeNode *> bfs;
        bfs.push(root);

        int count = 1;

        while(!bfs.empty())
        {
            root=bfs.front();
            bfs.pop();

            current.push_back(root->val);
            count--;

            if(root->left)
            {
                bfs.push(root->left);
            }

            if(root->right)
            {
                bfs.push(root->right);
            }

            // the current level is already enumerated, all children of current level are queued
            if(count==0)
            {
                result.push_back(current);
                current.clear();
                count = bfs.size();
            }
        }

        return result;
    }
};
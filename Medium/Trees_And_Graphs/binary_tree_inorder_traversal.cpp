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
// recursive
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
		inorderTraversalHelper(root, result);
		return result;
    }

	void inorderTraversalHelper(TreeNode* root, vector<int> &vec){
		if(!root)
		{
			return;
		}

		inorderTraversalHelper(root->left, vec);
		vec.push_back(root->val);
		inorderTraversalHelper(root->right, vec);
	}
};

// iteratively
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		if(!root)
			return {};


		vector<int> result;
		stack<TreeNode*> stack;
		TreeNode *current = root;

		while(current || !stack.empty())
		{
			// recur on left
			while(current){
				stack.push(current);
				current = current->left;
			}

			// walking back
			current = stack.top();
			stack.pop();
			result.push_back(current->val);
			current = current->right;
		}

		return result;
	}
};

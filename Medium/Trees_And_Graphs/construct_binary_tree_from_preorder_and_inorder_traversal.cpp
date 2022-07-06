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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      
		int rootIdx = 0;
		unordered_map<int, int> hmap;
		for(int i=0; i < inorder.size(); i++)
		{
			// map stores the value, index pair
			hmap[inorder[i]] = i;
		}

		return build(preorder, inorder, rootIdx, 0, inorder.size()-1, hmap);
    }

	TreeNode* build(vector<int>& preorder, vector<int>& inorder, int &rootIdx, int left, int right, unordered_map<int,int> &hmap)
	{
		if(left > right)
			return nullptr;

		// pivot will be the index of the root in inorder
		int pivot = hmap[preorder[rootIdx]];
		TreeNode* node = new TreeNode(inorder[pivot]); //inorder[pivot] == prorder[rootIdx]

		// next root would be one place later in the preorder
		rootIdx++;

		// left subtree's root will be in [left, pivot-1] in inorder
		node->left = build(preorder, inorder, rootIdx, left, pivot-1, hmap); // if this is not found, rootIdx wont increase
		// right subtree's root will be in [pivot-1, right] in inorder 
		node->right = build(preorder, inorder, rootIdx, pivot+1, right, hmap);


		return node;
	}
};

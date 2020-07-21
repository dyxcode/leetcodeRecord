/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
	int cur = 0;
	TreeNode* convertBST(TreeNode* root)
	{
		if (!root) return root;
		convertBST(root->right);
		root->val += cur;
		cur = root->val;
		convertBST(root->left);
		return root;
	}
};
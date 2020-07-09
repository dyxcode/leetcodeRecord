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
	bool dfs(TreeNode* l, TreeNode* r)
	{
		if (!l && !r)
			return true;
		if (!l || !r)
			return false;
		return (l->val == r->val) && dfs(l->left, r->right) && dfs(l->right, r->left);
	}

	bool isSymmetric(TreeNode* root)
	{
		if (!root)
			return true;
		return dfs(root->left, root->right);
	}
};
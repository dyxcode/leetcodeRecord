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
	bool dfs(TreeNode* p, int cur, int target)
	{
		if (!p->left && !p->right)
			return (cur + p->val) == target;
		bool ismatch = false;
		if (p->left)
			ismatch |= dfs(p->left, cur + p->val, target);
		if (p->right)
			ismatch |= dfs(p->right, cur + p->val, target);
		return ismatch;
	}

	bool hasPathSum(TreeNode* root, int sum)
	{
		if (!root)
			return false;
		return dfs(root, 0, sum);
	}
};
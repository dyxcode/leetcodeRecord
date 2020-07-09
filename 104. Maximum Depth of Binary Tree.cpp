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
	int dfs(TreeNode* p, int deep)
	{
		if (!p)
			return deep;
		return max(dfs(p->left, deep + 1), dfs(p->right, deep + 1));
	}
	int maxDepth(TreeNode* root)
	{
		return dfs(root, 0);
	}
};
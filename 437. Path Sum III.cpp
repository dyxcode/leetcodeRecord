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
	int dfs(TreeNode* p, int sum)
	{
		if (!p) return 0;
		sum -= p->val;
		return (sum == 0) + dfs(p->left, sum) + dfs(p->right, sum);
	}
	int pathSum(TreeNode* root, int sum)
	{
		if (!root) return 0;
		return dfs(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
	}
};
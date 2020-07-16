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
	int dfs(TreeNode* p, unordered_map<TreeNode*, int>& map)
	{
		if (!p)
			return 0;
		auto it = map.find(p);
		if (it != map.end())
			return it->second;
		int sum_grandchild = p->val;
		if (p->left)
		{
			sum_grandchild += dfs(p->left->left, map);
			sum_grandchild += dfs(p->left->right, map);
		}
		if (p->right)
		{
			sum_grandchild += dfs(p->right->left, map);
			sum_grandchild += dfs(p->right->right, map);
		}
		int sum_child = dfs(p->left, map) + dfs(p->right, map);
		int res = max(sum_child, sum_grandchild);
		map.insert({p, res});
		return res;
	}
	int rob(TreeNode* root)
	{
		unordered_map<TreeNode*, int> map;
		return dfs(root, map);
	}
};
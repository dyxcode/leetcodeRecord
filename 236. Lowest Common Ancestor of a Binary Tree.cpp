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
	void getParent(TreeNode* p, unordered_map<TreeNode*, TreeNode*>& parent_map)
	{
		if (p->left)
		{
			parent_map.insert({p->left, p});
			getParent(p->left, parent_map);
		}
		if (p->right)
		{
			parent_map.insert({p->right, p});
			getParent(p->right, parent_map);
		}
	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		unordered_map<TreeNode*, TreeNode*> parent_map;
		parent_map.insert({root, nullptr});
		getParent(root, parent_map);

		unordered_set<TreeNode*> p_path;
		while (p)
		{
			p_path.insert(p);
			p = parent_map[p];
		}
		while (q)
		{
			if (p_path.find(q) != p_path.end())
				return q;
			q = parent_map[q];
		}
		return nullptr;
	}
};
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
class Solution
{
public:
	TreeNode* setLeftToRight(TreeNode * l, TreeNode * r, TreeNode * p)
	{
		if (!l && !r)
		{
			return p;
		}
		if (!l)
		{
			return setLeftToRight(r->left, r->right, r);
		}
		if (!r)
		{
			auto ptr = setLeftToRight(l->left, l->right, l);
			p->right = p->left;
			p->left = nullptr;
			return ptr;
		}
		auto ptr_left = setLeftToRight(l->left, l->right, l);
		auto ptr_right = setLeftToRight(r->left, r->right, r);
		ptr_left->right = r;
		p->right = l;
		p->left = nullptr;
		return ptr_right;
	}
	void flatten(TreeNode* root)
	{
		if (!root)
			return;
		setLeftToRight(root->left, root->right, root);
	}
};
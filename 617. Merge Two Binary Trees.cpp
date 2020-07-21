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
	void merge(TreeNode* a, TreeNode* b, TreeNode*& p)
	{
		if (a && b)
		{
			a->val += b->val;
			merge(a->left, b->left, a->left);
			merge(a->right, b->right, a->right);
			return;
		}
		else if (b)
		{
			p = b;
		}
	}
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
	{
		if (t1 && t2)
		{
			t1->val += t2->val;
			merge(t1->left, t2->left, t1->left);
			merge(t1->right, t2->right, t1->right);
			return t1;
		}
		else if (t1)
			return t1;
		else
			return t2;
	}
};
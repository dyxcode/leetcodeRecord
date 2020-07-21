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
	int leftPath(TreeNode* p)
	{
		if (p->left)
			return 1 + max(rightPath(p->left), leftPath(p->left));
		else
			return 0;
	}
	int rightPath(TreeNode* p)
	{
		if (p->right)
			return 1 + max(rightPath(p->right), leftPath(p->right));
		else
			return 0;
	}
	int res = 0;
	int diameterOfBinaryTree(TreeNode* root)
	{
		if (!root) return 0;
		res = max(res, rightPath(root) + leftPath(root) + 1);
		diameterOfBinaryTree(root->right);
		diameterOfBinaryTree(root->left);
		return res - 1;
	}
};
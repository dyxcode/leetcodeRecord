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
	using It = vector<int>::iterator;

	TreeNode* createTree(It pre_b, It pre_e, It in_b, It in_e)
	{
		if (pre_b == pre_e)
			return NULL;
		int root_val = *pre_b;
		It root_ptr = find(in_b, in_e, root_val);
		TreeNode* r = new TreeNode(root_val);

		pre_b++;
		r->left = createTree(pre_b, pre_b + (root_ptr - in_b), in_b, root_ptr);

		pre_b += root_ptr - in_b;
		r->right = createTree(pre_b, pre_e, root_ptr + 1, in_e);

		return r;
	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
	{
		return createTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
	}
};
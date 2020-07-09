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
	int getMax(TreeNode * p)
	{
		if (p->left && p->right)
			return max(0, p->val + max(getMax(p->left), getMax(p->right)));
		if (p->left)
			return max(0, p->val + getMax(p->left));
		if (p->right)
			return max(0, p->val + getMax(p->right));
		return max(0, p->val);
	}

	int passRootSum(TreeNode * root)
	{
		int sum = root->val;

		if (root->left)
			sum += getMax(root->left);
		if (root->right)
			sum += getMax(root->right);
		return sum;
	}

	int maxPathSum(TreeNode* root)
	{
		vector<int> val_vec;
		if (root->left)
			val_vec.push_back(maxPathSum(root->left));
		if (root->right)
			val_vec.push_back(maxPathSum(root->right));

		val_vec.push_back(passRootSum(root));
		return *max_element(val_vec.begin(), val_vec.end());
	}
};
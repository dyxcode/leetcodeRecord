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
	TreeNode* buildTree(vector<int>& nums, int b, int e)
	{
		if (b > e)
			return NULL;
		int m = b - (b - e) / 2;
		TreeNode * p = new TreeNode(nums[m]);
		p->left = buildTree(nums, b, m - 1);
		p->right = buildTree(nums, m + 1, e);
		return p;
	}
	TreeNode* sortedArrayToBST(vector<int>& nums)
	{
		return buildTree(nums, 0, nums.size() - 1);
	}
};
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
	bool isValidBST(TreeNode* root)
	{
		stack<TreeNode*> stk;
		TreeNode* cur = root;
		int former;
		bool isfirst = true;
		while (!stk.empty() || cur)
		{
			if (cur)
			{
				stk.push(cur);
				cur = cur->left;
			}
			else
			{
				cur = stk.top();
				stk.pop();
				if (isfirst)
					isfirst = false;
				else if (cur->val <= former)
					return false;
				former = cur->val;
				cur = cur->right;
			}
		}
		return true;
	}
};
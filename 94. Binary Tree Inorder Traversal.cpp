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
	vector<int> inorderTraversal(TreeNode* root)
	{
		stack<TreeNode*> stk;
		vector<int> ret;
		TreeNode* cur = root;

		while (!stk.empty() || cur)
		{
			if (cur)
			{
				stk.push(cur);
				cur = cur->left;
			}
			else
			{
				ret.push_back(stk.top()->val);
				cur = stk.top()->right;
				stk.pop();
			}
		}
		return ret;
	}
};
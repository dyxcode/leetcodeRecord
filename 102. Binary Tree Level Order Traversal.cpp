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
	vector<vector<int>> levelOrder(TreeNode* root)
	{
		vector<vector<int>> ret;
		if (!root)
			return ret;

		vector<int> vec;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			int level_size = q.size();
			while (level_size--)
			{
				TreeNode* cur = q.front();
				q.pop();
				vec.push_back(cur->val);
				if (cur->left)
					q.push(cur->left);
				if (cur->right)
					q.push(cur->right);
			}
			ret.push_back(std::move(vec));
			vec.clear();
		}

		return ret;
	}
};
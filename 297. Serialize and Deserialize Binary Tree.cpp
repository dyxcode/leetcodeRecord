/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
	// Encodes a tree to a single string.
	void en_dfs(TreeNode* p, string& res)
	{
		if (!p)
		{
			res.append("n,");
			return;
		}
		res.append(to_string(p->val)).append(",");
		en_dfs(p->left, res);
		en_dfs(p->right, res);
	}
	string serialize(TreeNode* root)
	{
		string res;
		en_dfs(root, res);
		return res;
	}

	// Decodes your encoded data to tree.
	void de_dfs(TreeNode*& p, int& i, vector<int>& number)
	{
		if (number[i] == numeric_limits<int>::max())
		{
			p = nullptr;
			return;
		}
		p = new TreeNode(number[i]);
		de_dfs(p->left, ++i, number);
		de_dfs(p->right, ++i, number);
	}
	TreeNode* deserialize(string data)
	{
		TreeNode* root = nullptr;
		vector<int> number;
		int i = 0;
		while (i != data.size())
		{
			int j = data.find(',', i);
			string s = data.substr(i, j - i);
			if (s == "n")
				number.push_back(numeric_limits<int>::max());
			else
				number.push_back(stoi(s));
			i = j + 1;
		}
		i = 0;
		de_dfs(root, i, number);
		return root;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
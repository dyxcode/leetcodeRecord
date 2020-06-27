class Solution
{
public:
	vector<int> cur_vec;
	vector<vector<int>> ret;
	unordered_set<int> note_set;

	void dfs(vector<int>& nums)
	{
		if (cur_vec.size() == nums.size())
		{
			ret.push_back(cur_vec);
			return;
		}
		for (size_t i = 0; i < nums.size(); ++i)
		{
			auto retpair = note_set.insert(i);
			if (retpair.second)
			{
				cur_vec.push_back(nums[i]);
				dfs(nums);
				cur_vec.pop_back();
				note_set.erase(i);
			}
		}
	}

	vector<vector<int>> permute(vector<int>& nums)
	{
		dfs(nums);
		return ret;
	}
};
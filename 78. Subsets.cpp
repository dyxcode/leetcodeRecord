class Solution
{
public:
	vector<vector<int>> ret;
	vector<int> cur_vec;

	void dfs(vector<int>& nums, int s)
	{
		if (s == nums.size())
		{
			ret.push_back(cur_vec);
			return;
		}
		cur_vec.push_back(nums[s]);
		dfs(nums, s + 1);
		cur_vec.pop_back();
		dfs(nums, s + 1);
	}
	vector<vector<int>> subsets(vector<int>& nums)
	{
		dfs(nums, 0);
		return ret;
	}
};
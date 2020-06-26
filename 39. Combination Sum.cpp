class Solution
{
public:
	vector<vector<int>> ret;
	vector<int> cur_vec;

	void dfs(vector<int>& candidates, int target, int begin)
	{
		for (int i = begin; i < candidates.size(); ++i)
		{
			if (candidates[i] > target)
				continue;
			cur_vec.push_back(candidates[i]);
			if (candidates[i] == target)
			{
				ret.push_back(cur_vec);
			}
			else if (candidates[i] < target)
			{
				dfs(candidates, target - candidates[i], i);
			}
			cur_vec.pop_back();
		}
	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target)
	{
		dfs(candidates, target, 0);
		return ret;
	}
};
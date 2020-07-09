class Solution
{
public:
	int longestConsecutive(vector<int>& nums)
	{
		int res = 0;
		unordered_set<int> n_set{nums.begin(), nums.end()};
		for (auto && item : nums)
		{
			if (n_set.find(item - 1) != n_set.end())
				continue;
			int i = item + 1;
			while (n_set.find(i) != n_set.end())
				++i;
			res = max(res, i - item);
		}
		return res;
	}
};
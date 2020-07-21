class Solution
{
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
	{
		sort(people.begin(), people.end(), [](const vector<int>& lhs, const vector<int>& rhs) {
			if (lhs[0] != rhs[0])
				return lhs[0] > rhs[0];
			else
				return lhs[1] < rhs[1];
		});

		vector<vector<int>> ret(people.size());
		for (auto && item : people)
		{
			if (!ret[item[1]].empty())
			{
				for (int i = ret.size() - 2; i >= item[1]; --i)
					if (ret[i].empty()) continue;
					else ret[i + 1] = ret[i];
			}
			ret[item[1]] = item;
		}
		return ret;
	}
};
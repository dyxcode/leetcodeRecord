class Solution
{
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals)
	{
		sort(intervals.begin(), intervals.end(), [](vector<int>& lhs, vector<int>& rhs) {
			return lhs.back() < rhs.back();
		});
		vector<vector<int>> ret;
		for (int i = 0; i < intervals.size(); ++i)
		{
			int lo = intervals[i][0], hi = intervals[i][1];
			while (!ret.empty() && lo <= ret.back()[1])
			{
				lo = min(lo, ret.back()[0]);
				ret.pop_back();
			}
			ret.push_back({lo, hi});
		}
		return ret;
	}
};
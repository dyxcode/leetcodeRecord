class Solution
{
public:
	int getLastMoment(int n, vector<int>& left, vector<int>& right)
	{
		int res = 0;
		for (auto && item : left)
		{
			res = max(res, item);
		}
		for (auto && item : right)
		{
			res = max(n - item, res);
		}
		return res;
	}
};
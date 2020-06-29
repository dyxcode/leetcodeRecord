class Solution
{
public:
	int maxSubArray(vector<int>& nums)
	{
		int ret = numeric_limits<int>::min();
		int sum = 0;
		for (auto && item : nums)
		{
			if (sum >= 0)
				sum += item;
			else
				sum = item;
			ret = max(ret, sum);
		}
		return ret;
	}
};
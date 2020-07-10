class Solution
{
public:
	int rob(vector<int>& nums)
	{
		vector<int> dp(nums.size() + 2);
		int res = 0;
		for (int i = 0; i != nums.size(); ++i)
		{
			dp[i + 2] = max(dp[i + 1], dp[i] + nums[i]);
			res = max(dp[i + 2], res);
		}
		return res;
	}
};
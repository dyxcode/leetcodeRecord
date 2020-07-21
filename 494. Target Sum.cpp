class Solution
{
public:
	int findTargetSumWays(vector<int>& nums, int S)
	{
		int sum = 0;
		for (int i = 0; i < nums.size(); ++i)
			sum += nums[i];
		if (sum < S || (sum + S) % 2) return 0;
		sum = (sum + S) / 2;

		vector<vector<int>> dp(nums.size() + 1, vector<int>(sum + 1));
		dp[0][0] = 1;
		for (int i = 1; i <= nums.size(); ++i)
			for (int j = 0; j <= sum; ++j)
			{
				if (j - nums[i - 1] < 0)
					dp[i][j] = dp[i - 1][j];
				else
					dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
			}

		return dp.back().back();
	}
};
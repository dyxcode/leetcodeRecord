class Solution
{
public:
	int coinChange(vector<int>& coins, int amount)
	{
		vector<int> dp(amount + 1);

		for (int i = 1; i <= amount; ++i)
		{
			int min_num = amount + 1;
			for (int j = 0; j < coins.size(); ++j)
			{
				if (i - coins[j] >= 0)
				{
					min_num = min(min_num, dp[i - coins[j]]);
				}
			}
			if (min_num == amount + 1)
				dp[i] = amount + 1;
			else
				dp[i] = min_num + 1;
		}

		return (dp.back() == amount + 1) ? -1 : dp.back();
	}
};
class Solution
{
public:
	int maxProfit(vector<int>& prices)
	{
		vector<int> dp(prices.size());
		int ret = 0;
		for (int i = 1; i < prices.size(); ++i)
		{
			int profit = 0;
			for (int j = i - 1; j >= 0; --j)
			{
				if (prices[j] < prices[i])
				{
					if (j < 2)
						profit = max(profit, prices[i] - prices[j]);
					else
						profit = max(profit, prices[i] - prices[j] + dp[j - 2]);
				}
			}
			ret = max(profit, ret);
			dp[i] = ret;
		}

		return ret;
	}
};
class Solution
{
public:
	int maxProfit(vector<int>& prices)
	{
		if (prices.size() <= 1)
			return 0;
		int min_price = prices[0];
		int res = 0;
		for (int i = 1; i != prices.size(); ++i)
		{
			if (prices[i] > min_price)
			{
				res = max(res, prices[i] - min_price);
			}
			else if (prices[i] < min_price)
				min_price = prices[i];
		}
		return res;
	}
};
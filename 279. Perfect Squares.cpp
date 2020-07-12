class Solution
{
public:
	int numSquares(int n)
	{
		vector<int> square_vec;
		for (int i = 1; i * i <= n; ++i)
			square_vec.push_back(i * i);

		vector<vector<int>> dp(n, vector<int>(square_vec.size()));
		int min_num;
		for (int i = 0; i < n; ++i)
		{
			min_num = n;
			for (int j = 0; j < square_vec.size(); ++j)
			{
				if (square_vec[j] == i + 1)
					dp[i][j] = 1;
				else if (square_vec[j] > i + 1)
					dp[i][j] = min_num;
				else
					dp[i][j] = dp[i - square_vec[j]][j] + 1;
				min_num = min(min_num, dp[i][j]);
			}
		}
		return min_num;
	}
};
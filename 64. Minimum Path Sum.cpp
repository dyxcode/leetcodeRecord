class Solution
{
public:
	int minPathSum(vector<vector<int>>& grid)
	{
		if (grid.empty())
			return 0;
		vector<vector<int>> dp{grid.size(), vector<int>(grid[0].size())};
		dp.back().back() = grid.back().back();
		for (int i = grid.size() - 1; i >= 0; --i)
			for (int j = grid[0].size() - 1; j >= 0; --j)
			{
				if (i == grid.size() - 1 && j == grid[0].size() - 1)
					continue;
				else if (i == grid.size() - 1)
					dp[i][j] = dp[i][j + 1] + grid[i][j];
				else if (j == grid[0].size() - 1)
					dp[i][j] = dp[i + 1][j] + grid[i][j];
				else
					dp[i][j] = min(dp[i][j + 1], dp[i + 1][j]) + grid[i][j];
			}
		return dp[0][0];
	}
};
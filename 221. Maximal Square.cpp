class Solution
{
public:
	int maximalSquare(vector<vector<char>>& matrix)
	{
		if (matrix.empty()) return 0;
		vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size()));

		int res = 0;
		for (int i = 0; i < matrix.size(); ++i)
			for (int j = 0; j < matrix[0].size(); ++j)
			{
				if (matrix[i][j] == '0')
				{
					dp[i][j] = 0;
					continue;
				}
				if (i == 0 || j == 0)
				{
					dp[i][j] = 1;
					res = max(res, 1);
					continue;
				}
				int up, left;
				for (up = left = 1; up <= dp[i - 1][j - 1]; ++up, ++left)
				{
					if (matrix[i][j - left] == '0' || matrix[i - up][j] == '0')
						break;
				}
				dp[i][j] = up;
				res = max(res, up);
			}

		return res * res;
	}
};
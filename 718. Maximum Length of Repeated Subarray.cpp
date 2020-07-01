class Solution
{
public:
	int findLength(vector<int>& A, vector<int>& B)
	{
		vector<vector<int>> dp{A.size() + 1, vector<int>(B.size() + 1)};
		int ans = 0;
		for (size_t i = 0; i != A.size(); ++i)
			for (size_t j = 0; j != B.size(); ++j)
			{
				if (A[i] == B[j])
				{
					dp[i + 1][j + 1] = dp[i][j] + 1;
					ans = max(ans, dp[i + 1][j + 1]);
				}
			}

		return ans;
	}
};
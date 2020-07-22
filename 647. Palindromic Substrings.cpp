class Solution
{
public:
	int countSubstrings(string s)
	{
		vector<vector<bool>> dp(s.size(), vector<bool>(s.size()));
		int res = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			dp[i][i] = true;
			++res;
		}
		for (int i = s.size() - 2; i >= 0; --i)
			for (int j = i + 1; j < s.size(); ++j)
			{
				if (s[i] == s[j])
				{
					if (i + 1 == j)
						dp[i][j] = true;
					else
						dp[i][j] = dp[i + 1][j - 1];
					if (dp[i][j])
						++res;
				}
			}

		return res;
	}
};
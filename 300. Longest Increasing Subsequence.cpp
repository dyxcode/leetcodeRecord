class Solution
{
public:
	int lengthOfLIS(vector<int>& nums)
	{
		if (nums.empty()) return 0;
		vector<int> dp(nums.size());
		dp[0] = 1;
		int ret = 1;

		for (int i = 1; i < nums.size(); ++i)
		{
			int max_num = 0;
			for (int j = i - 1; j >= 0; --j)
			{
				if (nums[j] < nums[i])
					max_num = max(max_num, dp[j]);
			}
			dp[i] = max_num + 1;
			ret = max(ret, dp[i]);
		}
		return ret;
	}
};
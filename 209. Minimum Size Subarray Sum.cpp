class Solution
{
public:
	int minSubArrayLen(int s, vector<int>& nums)
	{
		int low = 0, high = 0;
		int cur_num = 0, ret = numeric_limits<int>::max();
		while (high < nums.size())
		{
			cur_num += nums[high];
			while (cur_num >= s)
			{
				ret = min(ret, high - low + 1);
				cur_num -= nums[low++];
			}
			++high;
		}
		return ret == numeric_limits<int>::max() ? 0 : ret;
	}
};
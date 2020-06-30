class Solution
{
public:
	bool canJump(vector<int>& nums)
	{
		int i = nums.size() - 1;
		while (i > 0)
		{
			int j = i - 1;
			while (j >= 0 && nums[j] + j < i)
				--j;
			if (j < 0)
				return false;
			else
				i = j;
		}
		return true;
	}
};
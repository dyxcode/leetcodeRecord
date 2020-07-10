class Solution
{
public:
	int majorityElement(vector<int>& nums)
	{
		int cur = nums[0];
		int time = 1;
		for (int i = 1; i < nums.size(); ++i)
			if (nums[i] != cur)
			{
				if (time == 1)
					cur = nums[i];
				else
					--time;
			}
			else
				++time;
		return cur;
	}
};
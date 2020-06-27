class Solution
{
public:
	int firstMissingPositive(vector<int>& nums)
	{
		for (int i = 0; i < nums.size(); ++i)
		{
			while (nums[i] != (i + 1) && nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1])
				swap(nums[i], nums[nums[i] - 1]);
		}
		int i = 0;
		for (; i < nums.size(); ++i)
			if (nums[i] != i + 1)
				break;
		if (i == nums.size())
			return nums.size() + 1;
		else
			return i + 1;
	}
};
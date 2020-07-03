class Solution
{
public:
	void sortColors(vector<int>& nums)
	{
		int i = -1, j = -1;
		for (int pos = 0; pos != nums.size(); ++pos)
		{
			if (nums[pos] == 0)
			{
				nums[pos] = nums[++j];
				nums[j] = 1;
				nums[++i] = 0;
			}
			else if (nums[pos] == 1)
			{
				swap(nums[++j], nums[pos]);
			}
		}
	}
};
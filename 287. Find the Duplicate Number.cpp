class Solution
{
public:
	int findDuplicate(vector<int>& nums)
	{
		vector<int> vec(nums.size());
		int res;
		for (int i = 0; i < nums.size(); ++i)
			if (++vec[nums[i]] > 1)
			{
				res = nums[i];
				break;
			}
		return res;
	}
};
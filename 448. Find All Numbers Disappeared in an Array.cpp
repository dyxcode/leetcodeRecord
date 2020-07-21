class Solution
{
public:
	vector<int> findDisappearedNumbers(vector<int>& nums)
	{
		for (int i = 0; i < nums.size(); ++i)
			while (nums[i] != (i + 1))
			{
				if (nums[i] == nums[nums[i] - 1])
					break;
				swap(nums[i], nums[nums[i] - 1]);
			}

		vector<int> ret;
		for (int i = 0; i < nums.size(); ++i)
			if (nums[i] != i + 1)
				ret.push_back(i + 1);
		return ret;
	}
};
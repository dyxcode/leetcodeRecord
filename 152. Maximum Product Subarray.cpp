class Solution
{
public:
	int maxProduct(vector<int>& nums)
	{
		if (nums.empty()) return 0;
		int max_num, min_num;
		int res;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] < 0)
				swap(max_num, min_num);
			if (i == 0)
			{
				res = max_num = min_num = nums[i];
				continue;
			}
			max_num = max(max_num*nums[i], nums[i]);
			min_num = min(min_num*nums[i], nums[i]);
			res = max(res, max_num);
		}
		return res;
	}
};
class Solution
{
public:
	vector<int> productExceptSelf(vector<int>& nums)
	{
		vector<int> res;
		int mul = 1;
		for (auto && item : nums)
		{
			res.push_back(mul);
			mul *= item;
		}
		mul = 1;
		for (int i = nums.size() - 1; i >= 0; --i)
		{
			res[i] *= mul;
			mul *= nums[i];
		}
		return res;
	}
};
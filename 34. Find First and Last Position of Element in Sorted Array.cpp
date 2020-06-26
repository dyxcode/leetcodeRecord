class Solution
{
public:
	int lowBound(vector<int>& nums, int l, int r, int target)
	{
		while (l <= r)
		{
			int m = l - (l - r) / 2;
			if (nums[m] >= target)
				r = m - 1;
			else
				l = m + 1;
		}
		return l;
	}
	int upBound(vector<int>& nums, int l, int r, int target)
	{
		while (l <= r)
		{
			int m = l - (l - r) / 2;
			if (nums[m] <= target)
				l = m + 1;
			else
				r = m - 1;
		}
		return r;
	}
	vector<int> searchRange(vector<int>& nums, int target)
	{
		vector<int> ret;
		int l = 0, r = nums.size() - 1;
		while (l <= r)
		{
			int m = l - (l - r) / 2;
			if (nums[m] == target)
			{
				ret.push_back(lowBound(nums, l, m, target));
				ret.push_back(upBound(nums, m, r, target));
				return ret;
			}
			else if (nums[m] < target)
			{
				l = m + 1;
			}
			else if (nums[m] > target)
			{
				r = m - 1;
			}
		}
		return {-1, -1};
	}
};
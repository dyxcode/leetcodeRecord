class Solution
{
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k)
	{
		deque<int> window;
		for (int i = 0; i < k; ++i)
		{
			if (window.empty())
				window.push_back(i);
			else
			{
				while (!window.empty() && nums[window.back()] <= nums[i])
					window.pop_back();
				window.push_back(i);
			}
		}

		vector<int> res;
		for (int i = k; i < nums.size(); ++i)
		{
			res.push_back(nums[window.front()]);
			if (window.front() == i - k)
				window.pop_front();
			while (!window.empty() && nums[window.back()] <= nums[i])
				window.pop_back();
			window.push_back(i);
		}
		res.push_back(nums[window.front()]);
		return res;
	}
};
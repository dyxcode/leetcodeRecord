class Solution
{
public:
	int trap(vector<int>& height)
	{
		if (height.empty())
			return 0;
		auto p = height.end() - 1;
		while (p >= height.begin() && *p == 0)
			--p;
		if (p + 1 == height.begin())
			return 0;
		height.erase(p + 1, height.end());
		int ret = 0;
		int i = 0;
		while (i < height.size() && height[i] == 0)
			++i;
		while (i < height.size() - 1)
		{
			int j = i + 1, tall = j, sum = 0, tall_sum = 0;
			while (j < height.size())
			{
				if (height[j] >= height[i])
					break;
				if (height[tall] < height[j])
				{
					tall = j;
					tall_sum = sum;
				}
				sum += height[j];
				++j;
			}

			if (j == height.size())
			{
				ret += (tall - i - 1) * height[tall] - tall_sum;
				i = tall;
			}
			else
			{
				ret += (j - i - 1) * height[i] - sum;
				i = j;
			}
		}
		return ret;
	}
};
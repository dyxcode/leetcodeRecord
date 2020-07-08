class Solution
{
public:
	int maximalRectangle(vector<vector<char>>& matrix)
	{
		if (matrix.empty())
			return 0;
		int width = matrix[0].size();
		vector<int> height(width);
		vector<int> left_bound(width, -1);
		vector<int> right_bound(width, width);

		int max_area = 0;

		for (int i = 0; i < matrix.size(); ++i)
		{
			for (int j = 0; j < width; ++j)
			{
				if (matrix[i][j] == '1')
					height[j]++;
				else
					height[j] = 0;
			}
			int left_min = -1;
			for (int j = 0; j < width; ++j)
			{
				left_bound[j] = max(left_bound[j], left_min);
				if (matrix[i][j] == '0')
				{
					left_bound[j] = -1;
					left_min = j;
				}
			}

			int right_min = width;
			for (int j = width - 1; j >= 0; --j)
			{
				right_bound[j] = min(right_bound[j], right_min);
				if (matrix[i][j] == '0')
				{
					right_bound[j] = width;
					right_min = j;
				}
			}

			for (int j = 0; j < width; ++j)
			{
				int cur_area = (right_bound[j] - left_bound[j] - 1) * height[j];
				max_area = max(cur_area, max_area);
			}
		}
		return max_area;
	}
};
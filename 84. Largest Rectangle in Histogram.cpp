class Solution
{
public:
	int largestRectangleArea(vector<int>& heights)
	{
		stack<int> s;
		vector<int> left_bound(heights.size());
		for (int i = 0; i != heights.size(); ++i)
		{
			while (!s.empty() && heights[s.top()] >= heights[i])
				s.pop();
			left_bound[i] = s.empty() ? -1 : s.top();
			s.push(i);
		}

		s = stack<int>();
		vector<int> right_bound(heights.size());
		for (int i = heights.size() - 1; i >= 0; --i)
		{
			while (!s.empty() && heights[s.top()] >= heights[i])
				s.pop();
			right_bound[i] = s.empty() ? heights.size() : s.top();
			s.push(i);
		}

		int res = 0;
		for (int i = 0; i != heights.size(); ++i)
		{
			res = max(res, heights[i] * (right_bound[i] - left_bound[i] - 1));
		}
		return res;
	}
};
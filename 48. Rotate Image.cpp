class Solution
{
public:
	void rotate(vector<vector<int>>& matrix)
	{
		size_t rounds = (matrix.size() + 1) / 2;
		for (size_t t = 0; t < rounds; ++t)
		{
			size_t begin = t, end = matrix.size() - 1 - t;
			for (size_t i = 0; i < end - begin; ++i)
			{
				int temp = matrix[end - i][begin];
				matrix[end - i][begin] = matrix[end][end - i];
				matrix[end][end - i] = matrix[begin + i][end];
				matrix[begin + i][end] = matrix[begin][begin + i];
				matrix[begin][begin + i] = temp;
			}
		}
	}
};
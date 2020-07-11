class Solution
{
public:
	bool search(vector<vector<int>>& matrix, int s_i, int s_j, int e_i, int e_j, int target)
	{
		if (e_i - s_i <= 1 && e_j - s_j <= 1)
		{
			for (int i = s_i; i <= e_i; ++i)
				for (int j = s_j; j <= e_j; ++j)
					if (matrix[i][j] == target)
						return true;
			return false;
		}
		int mid_i = s_i - (s_i - e_i) / 2;
		int mid_j = s_j - (s_j - e_j) / 2;
		if (matrix[mid_i][mid_j] == target)
			return true;
		else if (matrix[mid_i][mid_j] < target)
		{
			if (search(matrix, mid_i, mid_j, e_i, e_j, target))
				return true;
		}
		else if (matrix[mid_i][mid_j] > target)
		{
			if (search(matrix, s_i, s_j, mid_i, mid_j, target))
				return true;
		}
		if (search(matrix, s_i, mid_j + 1, mid_i - 1, e_j, target) ||
			search(matrix, mid_i + 1, s_j, e_i, mid_j - 1, target))
			return true;
		return false;
	}
	bool searchMatrix(vector<vector<int>>& matrix, int target)
	{
		if (matrix.empty()) return false;
		return search(matrix, 0, 0, matrix.size() - 1, matrix[0].size() - 1, target);
	}
};
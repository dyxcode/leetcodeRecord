class Solution
{
public:
	int numSubmat(vector<vector<int>>& mat)
	{
		int num = 0;
		int x = 200, y = 200;
		for (int i = 0; i < mat.size(); ++i)
			for (int j = 0; j < mat[0].size(); ++j)
			{
				if (mat[i][j] == 0)
					continue;
				x = 200, y = 200;
				for (int p = i; p < mat.size(); ++p)
					for (int q = j; q < mat[0].size(); ++q)
					{
						if (p >= x && q >= y)
							continue;
						if (mat[p][q] == 0)
						{
							x = p;
							y = q;
							continue;
						}
						++num;
					}
			}

		return num;
	}
};
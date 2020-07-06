class Solution
{
public:
	int m[100][100];

	int dfs(vector<vector<int>>& ob, int i, int j)
	{
		if (i < 0 || j < 0 || i >= ob.size() || j >= ob[0].size())
			return 0;
		if (ob[i][j] == 1)
			return 0;
		if (i == ob.size() - 1 && j == ob[0].size() - 1)
			return 1;
		if (m[i][j])
			return m[i][j];
		m[i][j] = dfs(ob, i + 1, j) + dfs(ob, i, j + 1);
		return m[i][j];
	}
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
	{
		memset(m, 0, sizeof(m));
		return dfs(obstacleGrid, 0, 0);
	}
};
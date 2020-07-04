class Solution
{
public:
	bool dfs(vector<vector<char>>& board, int i, int j, string& word, int pos)
	{
		if (pos == word.size())
			return true;
		if (i == board.size() || j == board[0].size() || i < 0 || j < 0)
			return false;

		if (board[i][j] == word[pos])
		{
			int temp = board[i][j];
			board[i][j] = 0;
			bool ret = dfs(board, i + 1, j, word, pos + 1) ||
				dfs(board, i - 1, j, word, pos + 1) ||
				dfs(board, i, j + 1, word, pos + 1) ||
				dfs(board, i, j - 1, word, pos + 1);
			board[i][j] = temp;
			return ret;
		}
		else return false;
	}
	bool exist(vector<vector<char>>& board, string word)
	{
		for (int i = 0; i < board.size(); ++i)
			for (int j = 0; j < board[0].size(); ++j)
				if (dfs(board, i, j, word, 0))
					return true;
		return false;
	}
};
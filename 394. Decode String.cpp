class Solution
{
public:
	string decodeString(string s)
	{
		string res;
		int repeat = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (isalpha(s[i]))
			{
				res.push_back(s[i]);
			}
			else if (isdigit(s[i]))
			{
				repeat = repeat * 10 + (s[i] - '0');
			}
			else if (s[i] == '[')
			{
				int bracket = 1;
				int j = i + 1;
				while (1)
				{
					if (s[j] == '[')
						++bracket;
					else if (s[j] == ']')
						--bracket;
					if (bracket == 0)
						break;
					++j;
				}
				string str = decodeString(s.substr(i + 1, j - i - 1));
				while (repeat--)
					res.append(str);
				repeat = 0;
				i = j;
			}
		}
		return res;
	}
};
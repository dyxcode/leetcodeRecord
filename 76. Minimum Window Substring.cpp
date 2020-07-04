class Solution
{
public:
	string minWindow(string s, string t)
	{
		int l = 0, r = 0, match_num = 0;
		unordered_map<char, int> needs, windows;
		int len = s.size() + 1, begin_pos;

		for (auto && ch : t)
			++needs[ch];
		while (r != s.size())
		{
			if (needs.count(s[r]) == 0)
			{
				++r;
				continue;
			}
			if (++windows[s[r]] == needs[s[r]])
				++match_num;
			while (match_num == needs.size())
			{
				if (len > r - l + 1)
				{
					len = r - l + 1;
					begin_pos = l;
				}
				if (needs.count(s[l]) == 0)
				{
					++l;
					continue;
				}
				if (--windows[s[l]] < needs[s[l]])
					--match_num;
				++l;
			}
			++r;
		}
		if (len == s.size() + 1)
			return "";
		else
			return s.substr(begin_pos, len);
	}
};
class Solution
{
public:
	unordered_set<string> unmatch_set;

	bool isPrefix(const string& s, const string& p)
	{
		size_t i;
		for (i = 0; i < s.size() && i < p.size(); ++i)
			if (s[i] != p[i])
				return false;
		if (i == p.size())
			return true;
		else
			return false;
	}
	bool isAllInDict(const string& s, const vector<string>& wordDict)
	{
		if (unmatch_set.find(s) != unmatch_set.end())
			return false;
		for (auto && item : wordDict)
		{
			if (isPrefix(s, item))
			{
				if (s.size() == item.size() || isAllInDict(s.substr(item.size()), wordDict))
				{
					return true;
				}
			}
		}
		unmatch_set.insert(s);
		return false;
	}

	bool wordBreak(string s, vector<string>& wordDict)
	{
		return isAllInDict(s, wordDict);
	}
};
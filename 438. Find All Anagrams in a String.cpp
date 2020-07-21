class Solution
{
public:
	vector<int> findAnagrams(string s, string p)
	{
		vector<int> res;
		if (s.size() < p.size()) return res;
		unordered_map<char, int> target, curmap;
		for (int i = 0; i < p.size(); ++i)
		{
			target[p[i]]++;
			curmap[s[i]]++;
		}
		if (target == curmap)
			res.push_back(0);
		for (int i = p.size(); i < s.size(); ++i)
		{
			curmap[s[i]]++;
			if (--curmap[s[i - p.size()]] == 0)
			{
				curmap.erase(s[i - p.size()]);
			}
			if (target == curmap)
				res.push_back(i - p.size() + 1);
		}
		return res;
	}
};
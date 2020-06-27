class Solution
{
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs)
	{
		unordered_map<string, vector<string>> res_map;
		for (auto && item : strs)
		{
			string temp{item};
			sort(temp.begin(), temp.end());
			auto it = res_map.find(temp);
			if (it != res_map.end())
				it->second.push_back(std::move(item));
			else
				res_map.insert({temp, {std::move(item)}});
		}
		vector<vector<string>> ret;
		for (auto && item : res_map)
		{
			ret.push_back(std::move(item.second));
		}
		return ret;
	}
};
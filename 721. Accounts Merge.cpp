class Solution
{
public:
	unordered_multimap<string, set<string>>::iterator
		isInSet(unordered_multimap<string, set<string>>& accounts_map, string& name, string& s)
	{
		auto range = accounts_map.equal_range(name);
		for (auto iter = range.first; iter != range.second; ++iter)
		{
			if (iter->second.find(s) != iter->second.end())
				return iter;
		}
		return accounts_map.end();
	}

	set<string> mergeSet(set<string>& lhs, set<string>& rhs)
	{
		set<string> ret_set;
		merge(lhs.begin(), lhs.end(), rhs.begin(), rhs.end(), inserter(ret_set, ret_set.end()));
		return ret_set;
	}

	vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
	{
		unordered_multimap<string, set<string>> accounts_map;

		for (size_t i = 0; i < accounts.size(); ++i)
		{
			set<string> cur_set;
			for (size_t j = 1; j < accounts[i].size(); ++j)
			{
				auto ptr_pair = isInSet(accounts_map, accounts[i][0], accounts[i][j]);
				if (ptr_pair != accounts_map.end())
				{
					if (!cur_set.empty())
					{
						set<string> temp_set(mergeSet(cur_set, ptr_pair->second));
						ptr_pair->second.swap(temp_set);
						cur_set.clear();
					}
					for (auto t = j + 1; t < accounts[i].size(); ++t)
					{
						auto ring_pair = isInSet(accounts_map, accounts[i][0], accounts[i][t]);
						if (ring_pair != accounts_map.end() && ring_pair != ptr_pair)
						{
							set<string> temp_set(mergeSet(ring_pair->second, ptr_pair->second));
							ptr_pair->second.swap(temp_set);
							accounts_map.erase(ring_pair);
						}
						else
						{
							ptr_pair->second.insert(accounts[i][t]);
						}
					}
					break;
				}
				else
				{
					cur_set.insert(accounts[i][j]);
				}
			}
			if (!cur_set.empty())
			{
				accounts_map.insert({accounts[i][0], std::move(cur_set)});
			}
		}

		vector<vector<string>> ret_vec;

		for (auto && item : accounts_map)
		{
			vector<string> person_vec;
			person_vec.push_back(item.first);
			for (auto && s : item.second)
				person_vec.push_back(std::move(s));
			ret_vec.push_back(std::move(person_vec));
		}

		return ret_vec;
	}
};
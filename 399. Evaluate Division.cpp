class Solution
{
private:
	unordered_map<string, string> parent;
	unordered_map<string, double> value;

	pair<string, double> findNode(const string& node)
	{
		auto it = parent.find(node);
		if (it == parent.end())
			return {"", -1};
		if (it->second != it->first)
		{
			double cur_value = value[it->first];
			auto root = findNode(it->second);
			return {root.first, cur_value * root.second};
		}
		else
		{
			return {it->first, 1};
		}
	}

	void unionNode(const string& lhs, const string& rhs, double v)
	{
		auto lhs_parent = findNode(lhs); // root_lhs, lhs/root_lhs
		auto rhs_parent = findNode(rhs); // root_rhs, rhs/root_rhs
		if (lhs_parent.first == rhs_parent.first)
			return;
		parent[lhs_parent.first] = rhs_parent.first;
		value[lhs_parent.first] = (1 / lhs_parent.second) * v * rhs_parent.second;
	}
public:
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
	{
		for (int i = 0; i < equations.size(); ++i)
		{
			if (parent.find(equations[i][0]) == parent.end())
				parent[equations[i][0]] = equations[i][0];
			if (parent.find(equations[i][1]) == parent.end())
				parent[equations[i][1]] = equations[i][1];
			unionNode(equations[i][0], equations[i][1], values[i]);
		}

		vector<double> ret;
		for (auto && item : queries)
		{
			auto f = findNode(item[0]); // f/r
			auto s = findNode(item[1]); // s/r
			if (f.first == "" || s.first == "")
				ret.push_back(-1.0);
			else if (f.first != s.first)
				ret.push_back(-1.0);
			else // f/s
				ret.push_back(f.second / s.second);
		}
		return ret;
	}
};
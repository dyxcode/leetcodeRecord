class Solution
{
public:
	struct compare
	{
		bool operator()(pair<int, int> a, pair<int, int> b)
		{
			return a.second < b.second;
		}
	};
	vector<int> topKFrequent(vector<int>& nums, int k)
	{
		unordered_map<int, int> map;
		for (int i = 0; i < nums.size(); ++i)
			map[nums[i]]++;

		priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pr;
		for (auto && item : map)
		{
			pr.push({item.first, item.second});
		}

		vector<int> ret;
		while (k--)
		{
			ret.push_back(pr.top().first);
			pr.pop();
		}
		return ret;
	}
};
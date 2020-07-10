class Solution
{
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
	{
		unordered_map<int, list<int>> map;
		vector<int> in_degree(numCourses);

		queue<int> zero_queue;
		int node_num = 0;
		for (auto && item : prerequisites)
		{
			in_degree[item[1]]++;
			map[item[0]].push_back(item[1]);
		}
		for (int i = 0; i < in_degree.size(); ++i)
		{
			if (in_degree[i] == 0)
			{
				zero_queue.push(i);
			}
		}
		while (!zero_queue.empty())
		{
			int t = zero_queue.front();
			zero_queue.pop();
			++node_num;
			for (auto && item : map[t])
			{
				if (--in_degree[item] == 0)
				{
					zero_queue.push(item);
				}
			}
		}
		return node_num == numCourses;
	}
};
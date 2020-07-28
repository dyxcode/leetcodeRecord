class Solution
{
public:
	int leastInterval(vector<char>& tasks, int n)
	{
		array<int, 26> a{0};
		int max_time = 0;
		int max_num = 1;

		for (int i = 0; i < tasks.size(); ++i)
		{
			++a[tasks[i] - 'A'];
		}
		for (int i = 0; i < a.size(); ++i)
		{
			if (a[i] > max_time)
			{
				max_time = a[i];
				max_num = 1;
			}
			else if (a[i] == max_time)
			{
				++max_num;
			}
		}
		int num = tasks.size() - max_time * max_num;
		if (num <= (max_time - 1) * (n - max_num + 1))
			return (max_time - 1) * (n + 1) + max_num;
		else
		{
			return tasks.size();
		}
	}
};
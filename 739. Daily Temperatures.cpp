class Solution
{
public:
	vector<int> dailyTemperatures(vector<int>& T)
	{
		stack<int> stk;
		deque<int> dq;
		for (int i = T.size() - 1; i >= 0; --i)
		{
			while (!stk.empty() && T[i] >= T[stk.top()])
				stk.pop();
			if (stk.empty())
				dq.push_front(0);
			else
				dq.push_front(stk.top() - i);
			stk.push(i);
		}
		vector<int> res{dq.begin(), dq.end()};
		return res;
	}
};
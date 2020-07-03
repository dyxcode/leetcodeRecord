class Solution
{
public:
	int m[100] = {0};
	int climbStairs(int n)
	{
		if (n < 0)
			return 0;
		else if (n == 0)
			return 1;
		else
		{
			if (!m[n - 1])
				m[n - 1] = climbStairs(n - 1) + climbStairs(n - 2);
			return m[n - 1];
		}
	}
};
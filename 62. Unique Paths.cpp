class Solution
{
public:
	int uniquePaths(int m, int n)
	{
		using ll = long long int;
		if (m > n) swap(m, n);
		ll s = m + n - 2, res = 1, fac = 1;
		for (ll i = m - 1; i > 0; --i, --s)
		{
			res *= s;
			fac *= i;
		}
		return res / fac;
	}
};
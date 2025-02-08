#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<int>v(8);
	for (auto& i : v)
	{
		cin >> i;
	}
	vector<int>temp(6);
	auto check = [&](int mask)
		{
			int a = v[3] - temp[4];
			if (a <= 0 || a > 13 || mask & (1 << a))
			{
				return false;
			}
			mask |= (1 << a);
			int b = v[7] - temp[5];
			if (b <= 0 || b > 13 || mask & (1 << b))
			{
				return false;
			}
			mask |= (1 << b);
			int c = v[0] - temp[0] - temp[2] - b;
			if (c <= 0 || c > 13 || mask & (1 << c))
			{
				return false;
			}
			mask |= (1 << c);
			int d = v[1] - temp[1] - temp[3] - temp[5];
			if (d <= 0 || d > 13 || mask & (1 << d))
			{
				return false;
			}
			mask |= (1 << d);
			int e = v[4] - temp[0] - temp[1] - a;
			if (e <= 0 || e > 13 || mask & (1 << e))
			{
				return false;
			}
			mask |= (1 << e);
			int f = v[5] - temp[2] - temp[3] - temp[4];
			if (f <= 0 || f > 13 || mask & (1 << f))
			{
				return false;
			}
			mask |= (1 << f);
			int g = v[6] - c - d;
			if (g <= 0 || g > 13 || mask & (1 << g))
			{
				return false;
			}
			mask |= (1 << g);
			return true;
		};
	int ans = 0;
	function<void(int, int)> dfs = [&](int depth, int mask)
		{
			if (depth == 6)
			{
				if (check(mask))
				{
					ans++;
				}
				return;
			}
			for (int i = 1; i <= 13; ++i)
			{
				if (!(mask & (1 << i)))
				{
					temp[depth] = i;
					dfs(depth + 1, mask | (1 << i));
				}
			}
		};
	dfs(0, 0);
	cout << ans;
	return 0;
}
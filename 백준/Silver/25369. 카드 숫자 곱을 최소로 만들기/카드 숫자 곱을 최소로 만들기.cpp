#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	ll ok = 1;
	for (int i = 0; i < n; ++i)
	{
		ll temp = 0;
		cin >> temp;
		ok *= temp;
	}
	vector<int>v;
	function<void(int)> dfs = [&](int depth)
		{
			if (depth == n)
			{
				ll res = 1;
				for (auto& i : v)
				{
					res *= i;
				}
				if (ok < res)
				{
					for (auto& i : v)
					{
						cout << i << ' ';
					}
					exit(0);
				}
				return;
			}
			for (int i = 1; i <= 9; ++i)
			{
				v.push_back(i);
				dfs(depth + 1);
				v.pop_back();
			}
		};
	dfs(0);
	cout << -1;
	return 0;
}
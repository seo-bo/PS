#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, mask = 0;
	cin >> n;
	vector<int>v;
	function<void(int)> dfs = [&](int mask) -> void
		{
			if (mask == (1 << n) - 1)
			{
				for (auto& i : v)
				{
					cout << i << ' ';
				}
				cout << '\n';
				return;
			}
			for (int i = 1; i <= n; ++i)
			{
				if (!(mask & (1 << (i - 1))))
				{
					mask |= (1 << (i - 1));
					v.push_back(i);
					dfs(mask);
					v.pop_back();
					mask &= ~(1 << (i - 1));
				}
			}
		};
	dfs(0);
	return 0;
}
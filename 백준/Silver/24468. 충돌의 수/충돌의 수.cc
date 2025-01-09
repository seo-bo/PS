#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int l = 0, n = 0, t = 0;
	cin >> l >> n >> t;
	vector<vector<int>>v(l + 1);
	auto input = [&]
		{
			int a = 0, p = 0;
			char b = 0;
			cin >> a >> b;
			p = (b == 'L') ? 0 : 1;
			v[a].push_back(p);
		};
	for (int i = 0; i < n; ++i)
	{
		input();
	}
	int ans = 0;
	for (int i = 1; i <= t; ++i)
	{
		vector<vector<int>>temp(l + 1);
		for (int j = 0; j <= l; ++j)
		{
			for (auto& k : v[j])
			{
				if (j == 0)
				{
					temp[1].push_back(1);
				}
				else if (j == l)
				{
					temp[l - 1].push_back(0);
				}
				else
				{
					if (k == 1)
					{
						temp[j + 1].push_back(1);
					}
					else
					{
						temp[j - 1].push_back(0);
					}
				}
			}
		}
		for (int j = 0; j <= l; ++j)
		{
			if (temp[j].size() > 1)
			{
				ans++;
				for (auto& k : temp[j])
				{
					k = (k + 1) % 2;
				}
			}
		}
		v = temp;
	}
	cout << ans;
	return 0;
}
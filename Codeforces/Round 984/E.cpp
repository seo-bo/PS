#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, k = 0, q = 0;
	cin >> n >> k >> q;
	vector<vector<int>>v(n, vector<int>(k, 0));
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	vector<vector<int>>temp(k, vector<int>(n, 0));
	for (int i = 0; i < k; ++i)
	{
		temp[i][0] = v[0][i];
		for (int j = 1; j < n; ++j)
		{
			temp[i][j] = temp[i][j - 1] | v[j][i];
		}
	}
	while (q--)
	{
		ll m = 0;
		cin >> m;
		ll left = 0, right = n - 1;
		bool check = false;
		for (int i = 0; i < m; ++i)
		{
			int a1 = 0, a2 = 0;
			char b1;
			cin >> a1 >> b1 >> a2;
			a1--;
			if (b1 == '>')
			{
				auto it = upper_bound(temp[a1].begin(), temp[a1].end(), a2) - temp[a1].begin();
				if (it == n)
				{
					check = true;
				}
				else
				{
					left = max(left, it);
				}
			}
			else if (b1 == '<')
			{
				auto it = lower_bound(temp[a1].begin(), temp[a1].end(), a2) - temp[a1].begin() - 1;
				if (it < 0)
				{
					check = true;
				}
				else
				{
					right = min(right, it);
				}
			}
		}
		if (check || left > right)
		{
			cout << -1 << '\n';
		}
		else
		{
			cout << left + 1 << '\n';
		}
	}
	return 0;
}

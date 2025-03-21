#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	vector<vector<char>>v(2, vector<char>(n));
	for (ll i = 0; i < 2; ++i)
	{
		string str;
		cin >> str;
		for (ll j = 0; j < n; ++j)
		{
			v[i][j] = str[j];
		}
	}
	ll ans = n * m - 1;
	vector<int>per;
	vector<vector<int>>dir = { {-1,-1},{1,1},{-1,1},{1,-1} };
	for (int j = 0; j < n; ++j)
	{
		for (int i = 0; i < 2; ++i)
		{
			if (v[i][j] == '.')
			{
				continue;
			}
			if (v[(i + 1) % 2][j] == v[i][j])
			{
				cout << -1;
				return 0;
			}
			per.push_back(i);
			for (int k = 0; k < 4; ++k)
			{
				int nx = i + dir[k][0];
				int ny = j + dir[k][1];
				if (m > 1)
				{
					ny = (ny + n) % n;
				}
				if (nx >= 0 && nx < 2 && ny >= 0 && ny < n)
				{
					if (v[nx][ny] == '#')
					{
						cout << -1;
						return 0;
					}
				}
			}
		}
	}
	if (per.empty())
	{
		cout << ans;
		return 0;
	}
	int len = per.size();
	vector<int>prefix(len + 2);
	int pre = per[0];
	per.push_back(per[0]);
	for (int i = 1; i <= len; ++i)
	{
		if (pre != per[i])
		{
			prefix[i] = prefix[i - 1] + 1;
			pre = per[i];
			continue;
		}
		prefix[i] += prefix[i - 1];
	}
	ans += prefix[len] * (m - 1) + prefix[len - 1];
	cout << ans;
	return 0;
}
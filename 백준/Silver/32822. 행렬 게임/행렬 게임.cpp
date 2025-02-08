#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>>a(n + 1, vector<int>(n + 1, 0)), b(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> b[i][j];
		}
	}
	vector<int>ans(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			ans[i] = max(ans[i], abs(a[j][i] - b[j][i]));
		}
	}
	ll res = 0;
	while (m--)
	{
		int a = 0;
		cin >> a;
		res += ans[a];
	}
	cout << res;
	return 0;
}
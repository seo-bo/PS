#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, m = 0, p = 0;
	cin >> n >> m >> p;
	vector<int>v(n + 1);
	v[0] = m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end(), [&](const int& a, const int& b)
		{
			return a > b;
		});
	int rank = 1;
	vector<int>ans(n + 1);
	ans[0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		if (v[i] != v[i - 1])
		{
			rank = i + 1;
		}
		ans[i] = rank;
	}
	for (int i = 0; i <= n - 1; ++i)
	{
		if (v[i] == m && v[i] != v[i + 1])
		{
			if (i + 1 <= p)
			{
				cout << ans[i];
				return 0;
			}
			else
			{
				cout << -1;
				return 0;
			}
		}
	}
	if (n + 1 <= p)
	{
		cout << ans[n];
	}
	else
	{
		cout << -1;
	}
	return 0;
}
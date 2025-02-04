#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, s = 0;
	cin >> n >> m >> s;
	vector<pii>v(n + 1, make_pair(-1, -1)); // f -> 폼, s -> 입금
	int idx = 0;
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		if (b == 0)
		{
			v[a].first = idx;
			idx++;
		}
		else
		{
			v[a].second = idx;
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if (v[i].first == -1)
		{
			v[i].first = idx;
		}
	}
	vector<int>ans;
	for (int i = 1; i <= n; ++i)
	{
		if (v[i].second != -1)
		{
			if (v[i].first == -1 || v[i].first - v[i].second >= s)
			{
				ans.push_back(i);
			}
		}
	}
	if (ans.empty())
	{
		cout << -1;
	}
	else
	{
		for (auto& i : ans)
		{
			cout << i << '\n';
		}
	}
	return 0;
}
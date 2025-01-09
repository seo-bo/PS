#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<pii>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i].first >> v[i].second;
	}
	vector<bool>pre(n + 1, false);
	pre[1] = true;
	for (int i = 1; i <= 99; ++i)
	{
		vector<bool>nxt(n + 1, false);
		for (int j = 1; j <= n; ++j)
		{
			if (pre[j])
			{
				auto [l, r] = v[j];
				nxt[l] = nxt[r] = true;
			}
		}
		if (i >= 10 && !nxt[1])
		{
			cout << i;
			return 0;
		}
		pre = nxt;
	}
	cout << -1;
	return 0;
}

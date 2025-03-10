#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, p = 0, e = 0;
	cin >> n >> p >> e;
	vector<pii>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i].first >> v[i].second;
	}
	function<void(int, int, int, int)> dfs = [&](int mask, int idx, int low, int high)
		{
			if (__builtin_popcount(mask) == p)
			{
				if (high < e)
				{
					return;
				}
				vector<int>ans(n + 1, 0);
				priority_queue<pii, vector<pii>, greater<pii>> pq;
				for (int i = 1; i <= n; ++i)
				{
					if (mask & (1 << i))
					{
						pq.push(make_pair(v[i].second - v[i].first, i));
						ans[i] = v[i].first;
					}
				}
				int ok = e - low;
				while (!pq.empty())
				{
					auto [a, b] = pq.top();
					pq.pop();
					int pivot = min(ok, a);
					ok -= pivot;
					ans[b] = v[b].first + pivot;
				}
				for (int i = 1; i <= n; ++i)
				{
					cout << ans[i] << ' ';
				}
				exit(0);
			}
			if (idx > n)
			{
				return;
			}
			dfs(mask, idx + 1, low, high);
			if (low + v[idx].first <= e)
			{
				dfs(mask | (1 << idx), idx + 1, low + v[idx].first, high + v[idx].second);
			}
		};
	dfs(0, 1, 0, 0);
	cout << -1;
	return 0;
}
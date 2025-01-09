#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		ll n = 0, m = 0, l = 0, ans = 0, k = 1;
		cin >> n >> m >> l;
		vector<pll>path(n), v(m);
		for (auto& [a, b] : path)
		{
			cin >> a >> b;
		}
		for (auto& [a, b] : v)
		{
			cin >> a >> b;
		}
		priority_queue<ll>pq;
		bool flag = true;
		int idx = 0;
		for (auto& [a, b] : path)
		{
			ll pos = a - 1;
			while (idx < v.size() && v[idx].first < a)
			{
				pq.push(v[idx++].second);
			}
			if (pos + k <= b)
			{
				while (!pq.empty() && pos + k <= b)
				{
					ans++;
					k += pq.top();
					pq.pop();
				}
			}
			if (pos + k <= b)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			cout << ans << '\n';
		}
		else
		{
			cout << -1 << '\n';
		}
	}
	return 0;
}

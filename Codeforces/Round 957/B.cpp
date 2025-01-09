#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0, m = 0;
		ll ans = 0;
		cin >> n >> m;
		vector<ll>v(m);
		priority_queue<ll>pq;
		for (auto& i : v)
		{
			cin >> i;
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < m - 1; ++i)
		{
			pq.push(v[i]);
		}
		ll now = v[m - 1];
		for (int i = 0; i < m - 1; ++i)
		{
			if (now == n)
			{
				break;
			}
			if (now + v[i] <= n)
			{
				ans += v[i] + v[i] - 1;
				now += v[i];
			}
			else
			{
				ans += n - now + n - now - 1;
				now = n;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

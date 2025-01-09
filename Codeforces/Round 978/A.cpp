#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		ll n = 0, r = 0;
		cin >> n >> r;
		priority_queue<ll>pq;
		for (int i = 0; i < n; ++i)
		{
			ll a = 0;
			cin >> a;
			pq.push(a);
		}
		ll ans = 0;
		while (r && !pq.empty() && pq.top() > 1)
		{
			ll a = pq.top();
			pq.pop();
			ll pivot = a / 2;
			ll res = min(r, pivot);
			ans += res * 2LL;
			r -= res;
			if (a % 2)
			{
				pq.push(1);
			}
		}
		if (pq.empty())
		{
			cout << ans << '\n';
			continue;
		}
		int len = pq.size();
		cout << ans + min(r, (ll)pq.size()) - (max(0LL, (ll)pq.size() - r)) << '\n';
	}
	return 0;
}

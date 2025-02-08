#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0, sum = 0, maxi = 0;
	cin >> n >> m;
	vector<ll>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	sort(v.rbegin(), v.rend());
	priority_queue<ll, vector<ll>, greater<ll>>pq;
	for (int i = 0; i < m; ++i)
	{
		pq.push(0);
	}
	for (auto& i : v)
	{
		ll p = pq.top();
		pq.pop();
		pq.push(p + i);
	}
	ll ans = 0;
	while (!pq.empty())
	{
		ans = max(ans, pq.top());
		pq.pop();
	}
	cout << ans;
	return 0;
}
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	priority_queue<pll, vector<pll>, greater<pll>>pq;
	ll n = 0, m = 0, ans = 0;
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		ll temp = 0;
		cin >> temp;
		pq.push(make_pair(0, temp));
		while (pq.size() > 2)
		{
			pq.pop();
		}
	}
	for (int i = 0; i < n; ++i)
	{
		auto a = pq.top();
		pq.pop();
		auto b = pq.top();
		pq.pop();
		ll temp = a.second + b.second;
		ll re = max(a.first, b.first);
		if (temp >= MOD)
		{
			re++;
			temp %= MOD;
		}
		pq.push(make_pair(re, temp));
		pq.push(a);
		pq.push(b);
		ans = (temp + MOD) % MOD;
		pq.pop();
	}
	cout << ans;
	return 0;
}
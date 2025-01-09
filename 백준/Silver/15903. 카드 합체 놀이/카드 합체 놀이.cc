#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, m = 0;
	ll ans = 0;
	cin >> n >> m;
	priority_queue<ll, vector<ll>, greater<ll>>pq;
	for (int i = 0; i < n; ++i)
	{
		ll temp = 0;
		cin >> temp;
		pq.push(temp);
	}
	while (m--)
	{
		ll a = pq.top(); pq.pop();
		ll b = pq.top(); pq.pop();
		for (int i = 0; i < 2; ++i)
		{
			pq.push(a + b);
		}
	}
	while (!pq.empty())
	{
		ans += pq.top();
		pq.pop();
	}
	cout << ans;
	return 0;
}
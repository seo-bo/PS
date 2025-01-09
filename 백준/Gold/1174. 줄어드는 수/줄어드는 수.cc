#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	if (n == 1)
	{
		cout << 0;
		return 0;
	}
	queue<pii>q;
	for (ll i = 1; i <= 9; ++i)
	{
		q.push(make_pair(i, i + 1));
	}
	ll cnt = 11;
	while (!q.empty())
	{
		auto [a, b] = q.front();
		q.pop();
		if (b == n)
		{
			cout << a;
			return 0;
		}
		for (ll i = 0; i <= 9; ++i)
		{
			if (i >= a % 10)
			{
				continue;
			}
			q.push(make_pair(a * 10 + i, cnt++));
		}
	}
	cout << -1;
	return 0;
}
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
	sort(v.begin() + 1, v.end(), [&](const pii& a, const pii& b)
		{
			return a.first - a.second < b.first - b.second;
		});
	vector<ll>prea(n + 2), preb(n + 2), diff;
	for (int i = 1; i <= n; ++i)
	{
		prea[i] = prea[i - 1] + v[i].first;
		preb[i] = preb[i - 1] + v[i].second;
		diff.push_back(v[i].first - v[i].second);
	}
	ll a = 0, b = 0;
	int q = 0;
	cin >> q;
	while (q--)
	{
		char c;
		ll temp = 0;
		cin >> c >> temp;
		if (c == 'A')
		{
			a += temp;
		}
		else
		{
			b += temp;
		}
		auto it = upper_bound(diff.begin(), diff.end(), b - a) - diff.begin();
		cout << preb[it] + it * b + prea[n] - prea[it] + (n - it) * a << '\n';
	}
	return 0;
}
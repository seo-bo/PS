#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int, int>ti;
typedef tuple<ll, ll, ll>tl;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	vector<ll>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	if (v[0] == 1)
	{
		cout << 0;
		return 0;
	}
	ll ans = 1, pp = v[n - 1], fail = (1LL << 19);
	queue<pll>q;
	q.push(make_pair(1, 1));
	while (!q.empty())
	{
		auto [a, b] = q.front();
		q.pop();
		if (ans >= fail || a > pp / 2 || a > (pp - 1LL) / 2LL)
		{
			cout << -1;
			return 0;
		}
		ll pivot1 = 2 * a, pivot2 = 2 * a + 1;
		if (!binary_search(v.begin(), v.end(), pivot1))
		{
			q.push(make_pair(pivot1, b + 1));
			ans++;
		}
		if (!binary_search(v.begin(), v.end(), pivot2))
		{
			q.push(make_pair(pivot2, b + 1));
			ans++;
		}
	}
	cout << ans;
	return 0;
}
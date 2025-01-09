#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll s = 0, t = 0;
	cin >> s >> t;
	set<ll>visited;
	if (s == t)
	{
		cout << 0;
		return 0;
	}
	queue<pair<ll, string>>q;
	q.push(make_pair(s, ""));
	visited.insert(s);
	while (!q.empty())
	{
		auto [a, b] = q.front();
		q.pop();
		if (a == t)
		{
			cout << b;
			return 0;
		}
		if (a && a <= LLONG_MAX / a && visited.find(a * a) == visited.end())
		{
			visited.insert(a * a);
			q.push(make_pair(a * a, b + '*'));
		}
		if (a <= LLONG_MAX - a && visited.find(a + a) == visited.end())
		{
			visited.insert(a + a);
			q.push(make_pair(a + a, b + '+'));
		}
		if (a - a > -1 && visited.find(a - a) == visited.end())
		{
			visited.insert(a - a);
			q.push(make_pair(a - a, b + '-'));
		}
		if (a && visited.find(a / a) == visited.end())
		{
			visited.insert(a / a);
			q.push(make_pair(a / a, b + '/'));
		}
	}
	cout << -1;
	return 0;
}
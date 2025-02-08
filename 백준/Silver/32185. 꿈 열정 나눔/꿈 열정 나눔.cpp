#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	ll sum = 0, a = 0, b = 0, c = 0;
	m--;
	for (int i = 0; i < 1; ++i)
	{
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		sum = a + b + c;
	}
	vector<pll>v;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a >> b >> c;
		if (a + b + c <= sum)
		{
			v.push_back(make_pair(a + b + c, i));
		}
	}
	cout << 0 << ' ';
	sort(v.rbegin(), v.rend());
	for (int i = 0; i < v.size() && m--; ++i)
	{
		cout << v[i].second << ' ';
	}
	return 0;
}
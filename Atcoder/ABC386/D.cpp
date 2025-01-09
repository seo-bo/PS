#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll, ll, char> ti;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<ti>v(m);
	for (auto& [a, b, c] : v)
	{
		cin >> a >> b >> c;
	}
	sort(v.begin(), v.end());
	ll pivot = LLONG_MAX;
	for (auto& [a, b, c] : v)
	{
		if (c == 'W')
		{
			pivot = min(pivot, b);
		}
		else if (b >= pivot)
		{
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}

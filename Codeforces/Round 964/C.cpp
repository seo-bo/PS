#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		ll n = 0, s = 0, m = 0;
		cin >> n >> s >> m;
		vector<pii>v(n);
		for (auto& [i, j] : v)
		{
			cin >> i >> j;
		}
		bool check = false;
		if (v[0].first >= s)
		{
			check = true;
		}
		for (int i = 1; i < n && !check; ++i)
		{
			if (v[i].first - v[i - 1].second >= s)
			{
				check = true;
			}
		}
		if (m - v[n - 1].second >= s)
		{
			check = true;
		}
		if (check)
		{
			cout << yes << '\n';
		}
		else
		{
			cout << no << '\n';
		}
	}
	return 0;
}

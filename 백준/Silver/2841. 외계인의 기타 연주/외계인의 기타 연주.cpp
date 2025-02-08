#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<vector<int>>v(7);
	int n = 0, p = 0, ans = 0;
	cin >> n >> p;
	for (int i = 0; i < n; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		while (!v[a].empty() && v[a].back() > b)
		{
			v[a].pop_back();
			ans++;
		}
		if (v[a].empty() || v[a].back() != b)
		{
			v[a].push_back(b);
			ans++;
		}
	}
	cout << ans;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	ll ans = 0;
	vector<pii>v;
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		if (a == b)
		{
			ans++;
			continue;
		}
		v.push_back(make_pair(min(a, b), max(a, b)));
	}
	sort(v.begin(), v.end());
	for (int i = 1; i < (int)v.size(); ++i)
	{
		if (v[i] == v[i - 1])
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}

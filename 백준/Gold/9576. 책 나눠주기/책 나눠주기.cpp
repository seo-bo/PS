#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0, m = 0;
		cin >> n >> m;
		vector<pii>v(m);
		for (auto& [a, b] : v)
		{
			cin >> a >> b;
		}
		sort(v.begin(), v.end(), [&](const pii& a, const pii& b)
			{
				return a.second < b.second;
			});
		set<int>s;
		for (int i = 1; i <= n; ++i)
		{
			s.insert(i);
		}
		int ans = 0;
		for (auto& [a, b] : v)
		{
			if (s.empty())
			{
				break;
			}
			auto it = s.lower_bound(a);
			if (it == s.end() || *it > b)
			{
				continue;
			}
			ans++;
			s.erase(*it);
		}
		cout << ans << '\n';
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		vector<pii>v(n);
		for (auto& i : v)
		{
			cin >> i.first >> i.second;
		}
		sort(v.begin(), v.end());
		int ans = 1;
		int a = v[0].second;
		for (int i = 1; i < n; ++i)
		{
			if (a > v[i].second)
			{
				ans++;
				a = min(a, v[i].second);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
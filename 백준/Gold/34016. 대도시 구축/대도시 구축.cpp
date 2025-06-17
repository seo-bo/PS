#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, m = 0;
	cin >> n >> m;
	ll ans = (n + 1) * (n + 2) / 2 - 3;
	vector<pii>s(m);
	for (auto& [a, b] : s)
	{
		cin >> a >> b;
		if (a > b)
		{
			swap(a, b);
		}
	}
	sort(s.begin(), s.end());
	if (m == 1 && s[0].first == 1)
	{
		ans++;
		if (s[0].first == 1 && s[0].second == 2)
		{
			ans++;
		}
	}
	else if (m == 2 && s[0].first == 1)
	{
		if (s[0].first == 1 && s[0].second == 2)
		{
			ans += 2;
			if (s[1].first == 1)
			{
				ans++;
				if (s[1].second == 3)
				{
					ans++;
				}
			}
			else if (s[1].first == 2 && s[1].second == 3)
			{
				ans++;
			}
		}
		else if (s[0].first == 1 && s[0].second == 3)
		{
			ans++;
			if (s[1].first == 1)
			{
				ans++;
			}
			else if (s[1].first == 2 && s[1].second == 3)
			{
				ans += 2;
			}
		}
		else
		{
			ans++;
			if (s[1].first == 1 || s[1].first == 2)
			{
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
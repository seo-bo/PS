#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
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
		int n = 0;
		cin >> n;
		vector<ll>v(n);
		bool check = true;
		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];
			if (i && ((v[i - 1] % 2) != (v[i] % 2)))
			{
				check = false;
			}
		}
		if (!check)
		{
			cout << -1 << '\n';
			continue;
		}
		int cnt = 1;
		vector<ll>ans;
		while (1)
		{
			if (!check)
			{
				break;
			}
			ll mini = *min_element(v.begin(), v.end());
			ll maxi = *max_element(v.begin(), v.end());
			if (!maxi)
			{
				break;
			}
			ll mid = (mini + maxi) / 2;
			ans.push_back(mid);
			bool check0 = false;
			bool check1 = false;
			for (auto& i : v)
			{
				i = llabs(i - mid);
				(i % 2) ? check1 = true : check0 = true;
			}
			if (check0 && check1)
			{
				check = false;
				break;
			}
		}
		if (!check)
		{
			cout << -1 << '\n';
			continue;
		}
		cout << ans.size() << '\n';
		for (auto& i : ans)
		{
			cout << i << ' ';
		}
		cout << '\n';
	}
	return 0;
}

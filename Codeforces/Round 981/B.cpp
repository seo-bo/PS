#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<lb, lb> plb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		vector<vector<ll>>v(n, vector<ll>(n, 0));
		for (auto& i : v)
		{
			for (auto& j : i)
			{
				cin >> j;
			}
		}
		ll ans = 0;
		for (int i = n - 1; i >= 0; --i)
		{
			ll pivot = LLONG_MAX;
			for (int j = 0; j + i < n; ++j)
			{
				pivot = min(pivot, v[j][j + i]);
			}
			if (pivot < 0)
			{
				ans += -pivot;
				for (int j = 0; j + i < n; ++j)
				{
					v[j][j + i] -= pivot;
				}
			}
		}
		for (int i = 1; i < n; ++i)
		{
			ll pivot = LLONG_MAX;
			for (int j = 0; j + i < n; ++j)
			{
				pivot = min(pivot, v[j + i][j]);
			}
			if (pivot < 0)
			{
				ans += -pivot;
				for (int j = 0; j + i < n; ++j)
				{
					v[j + i][j] -= pivot;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

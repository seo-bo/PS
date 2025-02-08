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
	int n = 0;
	cin >> n;
	ll ans = LLONG_MAX;
	vector<pii>v(n);
	set<int>x;
	set<int>y;
	for (auto& [i, j] : v)
	{
		cin >> i >> j;
		x.insert(i);
		y.insert(j);
	}
	for (auto x1 = x.begin(); x1 != x.end(); ++x1) // 4중포문 해결..?
	{
		for (auto x2 = x1; x2 != x.end(); ++x2)
		{
			auto y1 = y.begin();
			auto y2 = y.begin();
			while (y2 != y.end())
			{
				int cnt = 0;
				for (int i = 0; i < n; ++i)
				{
					auto [a, b] = v[i];
					if (*x1 <= a && a <= *x2 && *y1 <= b && b <= *y2)
					{
						cnt++;
					}
				}
				if (cnt < n / 2)
				{
					y2++;
				}
				else
				{
					ans = min(ans, (llabs(*x2 - *x1) + 2) * (llabs(*y2 - *y1) + 2));
					if (y1 == y2)
					{
						y2++;
					}
					else
					{
						y1++;
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}
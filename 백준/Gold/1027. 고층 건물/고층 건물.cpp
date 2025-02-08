#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef long double lb;

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<pll>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i].second;
		v[i].first = i;
	}
	auto cal = [&](int p1, int p2)
		{
			lb x1 = (lb)v[p1].first, y1 = (lb)v[p1].second;
			lb x2 = (lb)v[p2].first, y2 = (lb)v[p2].second;
			lb lin = (y2 - y1) / (x2 - x1);
			return make_pair(lin, (lin * (-x1) + y1));
		};
	int ans = 0;
	for (int i = 1; i <= n; ++i) // pivot
	{
		int temp = 0;
		for (int k = i - 1; k >= 1; --k)
		{
			auto [a, b] = cal(k, i);
			bool flag = true;
			for (int j = i - 1; j > k; --j)
			{
				if (a * v[j].first + b <= (lb)v[j].second)
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				temp++;
			}
		}
		for (int k = i + 1; k <= n; ++k)
		{
			auto [a, b] = cal(i, k);
			bool flag = true;
			for (int j = i + 1; j < k; ++j)
			{
				if (a * v[j].first + b <= (lb)v[j].second)
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				temp++;
			}
		}
		ans = max(ans, temp);
	}
	cout << ans;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0, m = 0;
	cin >> n >> k >> m;
	vector<ll>base(5, 0);
	vector<vector<ll>>cnt(5, vector<ll>(5, 0));
	for (int i = 0; i < n; ++i)
	{
		vector<ll>temp(5, 0), tt(5, 0);
		for (int j = 1; j <= 4; ++j)
		{
			cin >> temp[j];
		}
		for (int j = 1; j <= 4; ++j)
		{
			cin >> tt[j];
		}
		for (int j = 1; j <= 4; ++j)
		{
			base[temp[j]] += tt[j];
			cnt[temp[j]][j]++;
		}
	}
	vector<int>ot;
	for (int i = 1; i <= 4; ++i)
	{
		if (i == k)
		{
			continue;
		}
		ot.push_back(i);
	}
	for (int i = 0; i < (1 << 3); ++i)
	{
		if (__builtin_popcount(i) != (m - 1))
		{
			continue;
		}
		vector<ll>a, b;
		for (int j = 0; j < 3; ++j)
		{
			int pivot = ot[j];
			if (i & (1 << j))
			{
				a.push_back(pivot);
			}
			else
			{
				b.push_back(pivot);
			}
		}
		vector<pair<vector<ll>, ll>>cons;
		auto sv = [&](ll a, int b)
			{
				ll s = base[a] - base[k];
				vector<ll>temp(5);
				for (int i = 1; i <= 4; ++i)
				{
					temp[i] = cnt[a][i] - cnt[k][i];
				}
				if (b == 1)
				{
					ll aa = 0;
					cons.push_back(make_pair(temp, 1 - s));
				}
				else if (b == 2)
				{
					cons.push_back(make_pair(temp, -s));
				}
				else if (b == 3)
				{
					vector<ll>tt(5, 0);
					for (int i = 1; i <= 4; ++i)
					{
						tt[i] = -temp[i];
					}
					cons.push_back(make_pair(tt, 1 + s));
				}
				else if (b == 4)
				{
					vector<ll>tt(5, 0);
					for (int i = 1; i <= 4; ++i)
					{
						tt[i] = -temp[i];
					}
					cons.push_back(make_pair(tt, s));
				}
			};
		for (auto& i : a)
		{
			if (i < k)
			{
				sv(i, 2);
			}
			else
			{
				sv(i, 1);
			}
		}
		for (auto& i : b)
		{
			if (i < k)
			{
				sv(i, 3);
			}
			else
			{
				sv(i, 4);
			}
		}
		for (int d1 = 100; d1 >= -100; d1--)
		{
			for (int d2 = d1; d2 >= -100; d2--)
			{
				for (int d3 = d2; d3 >= -100; d3--)
				{
					ll sum = d1 + d2 + d3;
					ll minus = -sum;
					if (minus < -100 || minus > 100)
					{
						continue;
					}
					if (minus > d3)
					{
						continue;
					}
					bool flag = true;
					for (auto& [a, b] : cons)
					{
						ll as = a[1] * d1 + a[2] * d2 + a[3] * d3 + a[4] * minus;
						if (as < b)
						{
							flag = false;
							break;
						}
					}
					if (flag)
					{
						cout << d1 << ' ' << d2 << ' ' << d3 << ' ' << minus << '\n';
						return 0;
					}
				}
			}
		}
	}
	cout << -1;
	return 0;
}
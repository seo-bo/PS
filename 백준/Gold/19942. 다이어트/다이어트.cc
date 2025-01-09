#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int, int, int, int, int>ti;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	ti pivot;
	vector<int>res;
	vector<ti>v(n);
	for (int i = 0; i < 1; ++i)
	{
		int a = 0, b = 0, c = 0, d = 0;
		cin >> a >> b >> c >> d;
		pivot = make_tuple(a, b, c, d, INT_MAX);
	}
	auto [pa, pb, pc, pd, x] = pivot;
	ll ans = INT_MAX;
	for (auto& [a, b, c, d, e] : v)
	{
		cin >> a >> b >> c >> d >> e;
	}
	for (int i = 0; i < (1 << n); ++i)
	{
		vector<int>temp;
		ti nam = make_tuple(0, 0, 0, 0, 0);
		auto& [a, b, c, d, e] = nam;
		for (int j = 0; j < n; ++j)
		{
			if (i & (1 << j))
			{
				a += get<0>(v[j]);
				b += get<1>(v[j]);
				c += get<2>(v[j]);
				d += get<3>(v[j]);
				e += get<4>(v[j]);
				temp.push_back(j + 1);
			}
		}
		if (a >= pa && b >= pb && c >= pc && d >= pd)
		{
			if (ans > e)
			{
				ans = e;
				res = temp;
			}
			else if (ans == e)
			{
				res = min(res, temp);
			}
		}
	}
	if (ans == INT_MAX)
	{
		cout << -1;
		return 0;
	}
	cout << ans << '\n';
	for (auto& i : res)
	{
		cout << i << ' ';
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, d = 0, m = 0;
	cin >> n >> d >> m;
	vector<pii>v(m);
	for (int i = 0; i < m; ++i)
	{
		cin >> v[i].first;
		v[i].second = i + 1;
	}
	sort(v.begin(), v.end(), [&](const pii& a, const pii& b)
		{
			return a.first < b.first;
		});
	auto cal = [&](int mid)
		{
			int idx = 0;
			for (int day = 1; day <= n && idx < m; ++day)
			{
				for (int j = 0; j < mid && idx < m; ++j)
				{
					if (v[idx].first > day)
					{
						break;
					}
					if (day > v[idx].first + d)
					{
						return false;
					}
					idx++;
				}
			}
			return (idx >= m);
		};
	int left = 1, right = m, ans = 0;
	while (left <= right)
	{
		int mid = (left + right) >> 1;
		if (cal(mid))
		{
			right = mid - 1;
			ans = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	cout << ans << '\n';
	int idx = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < ans && idx < m; ++j)
		{
			if (v[idx].first > i)
			{
				break;
			}
			cout << v[idx].second << ' ';
			idx++;
		}
		cout << 0 << '\n';
	}
	return 0;
}
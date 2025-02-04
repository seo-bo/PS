#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int, int, int> ti;
typedef pair<int, ti> pt;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<pt>pivot(n + 1);
	vector<int>ans(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		pivot[i].first = i;
		for (int j = 1; j <= n; ++j)
		{
			int temp = 0;
			cin >> temp;
			if (temp == -1)
			{
				get<0>(pivot[j].second)++;
			}
			else if (temp == 1)
			{
				get<2>(pivot[j].second)++;
			}
			else
			{
				if (i != j)
				{
					cout << -1;
					return 0;
				}
				get<1>(pivot[j].second)++;
			}
		}
	}
	sort(pivot.begin() + 1, pivot.end(), [&](const pt& a, const pt& b)
		{
			return get<2>(a.second) > get<2>(b.second);
		});
	int cnt = n;
	for (int i = 1; i <= n; ++i)
	{
		auto [a, b, c] = pivot[i].second;
		if (a + b + c != n)
		{
			cout << -1;
			return 0;
		}
		if (b != 1)
		{
			cout << -1;
			return 0;
		}
		if (cnt - 1 != c)
		{
			cout << -1;
			return 0;
		}
		ans[pivot[i].first] = cnt--;
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}
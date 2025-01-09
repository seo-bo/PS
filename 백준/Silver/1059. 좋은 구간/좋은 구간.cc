#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, m = 0, ans = 0;
	cin >> n;
	vector<int>v(n, 0);
	for (auto& i : v)
	{
		cin >> i;
		if (i == m)
		{
			cout << 0;
			return 0;
		}
	}
	cin >> m;
	v.push_back(m);
	sort(v.begin(), v.end());
	int left = 0, right = 0;
	for (int i = 0; i < n; ++i)
	{
		if (v[i] == m)
		{
			left = (i - 1 >= 0) ? v[i - 1] + 1 : 1;
			right = v[i + 1] - 1;
		}
	}
	for (int i = left; i <= m; ++i)
	{
		for (int j = m; j <= right; ++j)
		{
			if (i < j)
			{
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, m = 0, ans = 0;
	cin >> n >> m;
	vector<vector<int>>v(n, vector<int>(m, 0));
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		int one = 0, two = 0;
		bool o = false, t = false;
		for (int j = 0; j < m; ++j)
		{
			if (v[i][j] == 1)
			{
				if (!j || v[i][j - 1] != v[i][j])
				{
					one++;
				}
				o = true;
			}
			else if (v[i][j] == 2)
			{
				if (!j || v[i][j - 1] != v[i][j])
				{
					two++;
				}
				t = true;
			}
			else
			{
				if (o || t)
				{
					ans += (1 + min(one, two));
					one = two = 0;
					o = false, t = false;
				}
			}
		}
		if (o || t)
		{
			ans += (1 + min(one, two));
		}
	}
	cout << ans;
	return 0;
}
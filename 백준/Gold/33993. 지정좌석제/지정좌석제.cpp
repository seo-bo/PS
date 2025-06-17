#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int q = 0, r = 0, c = 0, w = 0;
	cin >> q >> r >> c >> w;
	w /= 2;
	int n = max(r, c);
	vector<vector<int>>v(n + 1, vector<int>(n + 1, 0));
	for (int i = 0; i < q; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		v[a][b] = 1;
	}
	vector<vector<int>>prefix(n + 2, vector<int>(n + 2, 0));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + v[i][j];
		}
	}
	auto cal = [&](int i, int j)
		{
			int x1 = max(0, i - w - 1), x2 = min(n, i + w), y1 = max(0, j - w - 1), y2 = min(n, j + w);
			return prefix[x1][y1] - prefix[x2][y1] - prefix[x1][y2] + prefix[x2][y2];
		};
	int ans = 0, x = 1, y = 1;
	for (int i = 1; i <= r; ++i)
	{
		for (int j = 1; j <= c; ++j)
		{
			if (v[i][j])
			{
				continue;
			}
			int p = cal(i, j);
			if (p > ans)
			{
				ans = p;
				x = i, y = j;
			}
		}
	}
	cout << ans << '\n';
	cout << x << ' ' << y;
	return 0;
}
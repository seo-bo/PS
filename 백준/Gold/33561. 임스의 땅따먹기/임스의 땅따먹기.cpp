#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<int>>sum(n + 2, vector<int>(n + 2, 0));
	vector<vector<int>>cnt(n + 2, vector<int>(n + 2, 0));
	vector<vector<int>>v(n + 1, vector<int>(n + 1, 0));
	vector<vector<int>>c(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> v[i][j];
			if (!v[i][j])
			{
				c[i][j]++;
			}
			sum[i][j] = v[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
			cnt[i][j] = c[i][j] + cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1];
		}
	}
	auto query = [&](vector<vector<int>>& pfx, int a, int b, int c, int d)
		{
			return pfx[c][d] - pfx[c][b - 1] - pfx[a - 1][d] + pfx[a - 1][b - 1];
		};
	int q = 0;
	cin >> q;
	vector<int>temp(q);
	for (auto& i : temp)
	{
		cin >> i;
	}
	int ans = INT_MIN;
	sort(temp.rbegin(), temp.rend());
	vector<int>prefix(q + 1);
	for (int i = 1; i <= q; ++i)
	{
		prefix[i] = prefix[i - 1] + temp[i - 1];
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			for (int k = 0; k <= n; ++k)
			{
				int nx = i + k;
				int ny = j + k;
				if (nx <= n && ny <= n)
				{
					int a = query(sum, i, j, nx, ny);
					int b = query(cnt, i, j, nx, ny);
					if (b > q)
					{
						continue;
					}
					ans = max(ans, a + prefix[b]);
				}
				else
				{
					break;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
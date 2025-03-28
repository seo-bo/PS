#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int>v(n + 1), prefix(n + 2);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		prefix[i] = prefix[i - 1] + v[i];
	}
	vector<vector<int>>dp(n + 1, vector<int>(m + 1, -1));
	vector<vector<int>>cost(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			int mid = (i + j) / 2;
			int left = v[mid] * (mid - i) - (prefix[mid - 1] - prefix[i - 1]);
			int right = prefix[j] - prefix[mid] - v[mid] * (j - mid);
			cost[i][j] = left + right;
		}
	}
	vector<vector<int>>path(n + 1, vector<int>(m + 1, 0));
	function<int(int, int)> dfs = [&](int idx, int cnt)
		{
			if (idx > n)
			{
				return (cnt) ? (int)1e7 : 0;
			}
			if (!cnt)
			{
				return (int)1e7;
			}
			if (dp[idx][cnt] != -1)
			{
				return dp[idx][cnt];
			}
			int res = 1e7;
			for (int i = idx; i <= n; ++i)
			{
				int temp = cost[idx][i] + dfs(i + 1, cnt - 1);
				if (res > temp)
				{
					res = temp;
					path[idx][cnt] = i;
				}
			}
			return dp[idx][cnt] = res;
		};
	function<void(int, int)> bf = [&](int idx, int cnt)
		{
			if (!cnt)
			{
				return;
			}
			int pivot = path[idx][cnt];
			cout << v[(idx + pivot) / 2] << ' ';
			bf(pivot + 1, cnt - 1);
		};
	cout << dfs(1, m) << '\n';
	bf(1, m);
	return 0;
}
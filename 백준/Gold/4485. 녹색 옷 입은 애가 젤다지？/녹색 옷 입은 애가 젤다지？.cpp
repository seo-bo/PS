#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int cnt = 1;
	while (1)
	{
		int n = 0;
		cin >> n;
		if (!n)
		{
			break;
		}
		vector<vector<int>>v(n, vector<int>(n));
		vector<vector<int>>dp(n, vector<int>(n, INT_MAX));
		vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
		for (auto& i : v)
		{
			for (auto& j : i)
			{
				cin >> j;
			}
		}
		dp[0][0] = v[0][0];
		priority_queue < tuple<int, int, int>, vector< tuple<int, int, int>>, greater< tuple<int, int, int>>>pq;
		pq.push(make_tuple(v[0][0], 0, 0)); // 잃는 돈 , x , y
		while (!pq.empty())
		{
			auto [a, b, c] = pq.top();
			pq.pop();
			if (dp[b][c] < a)
			{
				continue;
			}
			for (int i = 0; i < 4; ++i)
			{
				int nx = b + dir[i][0];
				int ny = c + dir[i][1];
				if (nx >= 0 && nx < n && ny >= 0 && ny < n)
				{
					if (dp[nx][ny] > dp[b][c] + v[nx][ny])
					{
						dp[nx][ny] = dp[b][c] + v[nx][ny];
						pq.push(make_tuple(dp[nx][ny], nx, ny));
					}
				}
			}
		}
		cout << "Problem " << cnt++ << ": " << dp[n - 1][n - 1] << '\n';
	}
	return 0;
}
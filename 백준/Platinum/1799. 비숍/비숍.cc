#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
typedef tuple<int, int, bool>tp;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, cnt = 1;
	cin >> n;
	int x = n - 1, y = 0, p = 2 * n;
	bool check = false;
	vector<vector<pii>>temp(p);
	vector<vector<int>>v(n, vector<int>(n, 0));
	vector<vector<pii>>lr(n, vector<pii>(n));
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	int ppi = 0;
	while (cnt < p) // 아래 대각
	{
		int nx = x, ny = y;
		while (nx >= 0 && nx < n && ny >= 0 && ny < n)
		{
			if (v[nx][ny])
			{
				temp[cnt].push_back(make_pair(nx, ny));
				lr[nx][ny].first = cnt;
			}
			++nx, ++ny;
		}
		(!check) ? (x--) : (y++);
		if (!check && x < 0)
		{
			x = 0, y = 1;
			check = true;
		}
		cnt++;
	}
	cnt = 1, x = 0, y = 0, check = false;
	while (cnt < p) // 위 대각
	{
		int nx = x, ny = y;
		while (nx >= 0 && nx < n && ny >= 0 && ny < n)
		{
			if (v[nx][ny])
			{
				lr[nx][ny].second = cnt;
			}
			++nx, --ny;
		}
		(!check) ? (y++) : (x++);
		if (!check && y >= n)
		{
			x = 1, y = n - 1;
			check = true;
		}
		cnt++;
	}
	auto cal = [&](int depth, int left, int right)
		{
			int c = 0;
			for (int i = depth; i < p; ++i)
			{
				for (auto& [a, b] : temp[i])
				{
					auto [_, __] = lr[a][b];
					if (!(left & (1 << _)) && !(right & (1 << __)))
					{
						c++;
						break;
					}
				}
			}
			return c;
		};
	int ans = 0;
	function<void(int, int, int, int)> dfs = [&](int depth, int pivot, int left, int right)
		{
			if (depth == p)
			{
				ans = max(ans, pivot);
				return;
			}
			if (pivot + cal(depth, left, right) <= ans)
			{
				return;
			}
			for (auto& [i, j] : temp[depth])
			{
				auto [a, b] = lr[i][j];
				if (!(left & (1 << a)) && !(right & (1 << b)))
				{
					dfs(depth + 1, pivot + 1, left | (1 << a), right | (1 << b));
				}
			}
			dfs(depth + 1, pivot, left, right);
		};
	dfs(1, 0, 0, 0);
	cout << ans;
	return 0;
}
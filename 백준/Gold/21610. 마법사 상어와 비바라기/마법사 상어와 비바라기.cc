#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int r = 0, c = 0;
	cin >> r >> c;
	vector<vector<int>>v(r, vector<int>(r, 0));
	vector<vector<bool>>visited(r, vector<bool>(r, false));
	vector<vector<int>>dir = { {0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1} };
	vector<int>copy = { 1,3,5,7 };
	vector<pii>query(c);
	vector<pii>temp;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < r; ++j)
		{
			cin >> v[i][j];
		}
	}
	for (auto& [i, j] : query)
	{
		cin >> i >> j;
		i--;
	}
	temp.push_back(make_pair(r - 1, 0)), temp.push_back(make_pair(r - 1, 1)), temp.push_back(make_pair(r - 2, 0)), temp.push_back(make_pair(r - 2, 1));
	for (auto& [i, j] : temp)
	{
		auto [a, b] = query[0];
		i = i + dir[a][0] * b;
		j = j + dir[a][1] * b;
		(i >= 0) ? i %= r : i = (i % r + r) % r;
		(j >= 0) ? j %= r : j = (j % r + r) % r;
		visited[i][j] = true;
	}
	for (int i = 1; i <= c; ++i)
	{
		for (auto& [a, b] : temp)
		{
			v[a][b]++;
		}
		for (auto& [a, b] : temp)
		{
			int cnt = 0;
			for (auto& k : copy)
			{
				int nx = a + dir[k][0];
				int ny = b + dir[k][1];
				if (nx >= 0 && nx < r && ny >= 0 && ny < r && v[nx][ny])
				{
					cnt++;
				}
			}
			v[a][b] += cnt;
		}
		if (i == c)
		{
			break;
		}
		vector<vector<bool>>vis(r, vector<bool>(r, false));
		vector<pii>().swap(temp);
		for (int x = 0; x < r; ++x)
		{
			for (int y = 0; y < r; ++y)
			{
				if (!visited[x][y] && v[x][y] >= 2)
				{
					v[x][y] -= 2;
					auto [a, b] = query[i];
					int nx = x + dir[a][0] * b;
					int ny = y + dir[a][1] * b;
					(nx > 0) ? nx %= r : nx = (nx % r + r) % r;
					(ny > 0) ? ny %= r : ny = (ny % r + r) % r;
					vis[nx][ny] = true;
					temp.push_back(make_pair(nx, ny));
				}
			}
		}
		swap(vis, visited);
	}
	ll ans = 0;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < r; ++j)
		{
			if (!visited[i][j] && v[i][j] >= 2)
			{
				v[i][j] -= 2;
			}
			ans += v[i][j];
		}
	}
	cout << ans;
	return 0;
}
#include <bits/stdc++.h>
#include <unordered_set>
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
	int n = 0, m = 0;
	cin >> m >> n;
	vector<vector<int>>v(n, vector<int>(m));
	vector<vector<int>>visited(n, vector<int>(m, INT_MAX));
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; ++j)
		{
			v[i][j] = str[j] - '0';
		}
	}
	deque<tuple<int, int, int>>dq;
	visited[0][0] = v[0][0];
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	dq.push_front(make_tuple(0, 0, visited[0][0]));
	while (!dq.empty())
	{
		auto [a, b, c] = dq.front();
		if (a == n - 1 && b == m - 1)
		{
			cout << c;
			break;
		}
		dq.pop_front();
		for (int i = 0; i < 4; ++i)
		{
			int nx = a + dir[i][0];
			int ny = b + dir[i][1];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				int nd = visited[a][b] + v[nx][ny];
				if (visited[nx][ny] > nd)
				{
					visited[nx][ny] = nd;
					if (v[nx][ny])
					{
						dq.push_back(make_tuple(nx, ny, nd));
					}
					else
					{
						dq.push_front(make_tuple(nx, ny, nd));
					}
				}
			}
		}
	}
	return 0;
}
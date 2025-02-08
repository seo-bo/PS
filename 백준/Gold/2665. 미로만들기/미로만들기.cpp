#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<int>>v(n, vector<int>(n, 0));
	vector<vector<int>>visited(n, vector<int>(n, INT_MAX));
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < n; ++j)
		{
			v[i][j] = (str[j] - '0' + 1) % 2;
		}
	}
	deque<ti>dq;
	visited[0][0] = v[0][0];
	dq.push_back(make_tuple(0, 0, visited[0][0]));
	while (!dq.empty())
	{
		auto [x, y, a] = dq.front();
		if (x == n - 1 && y == n - 1)
		{
			cout << a;
			break;
		}
		dq.pop_front();
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n)
			{
				int cost = a + v[nx][ny];
				if (visited[nx][ny] > cost)
				{
					visited[nx][ny] = cost;
					if (v[nx][ny])
					{
						dq.push_back(make_tuple(nx, ny, cost));
					}
					else
					{
						dq.push_front(make_tuple(nx, ny, cost));
					}
				}
			}
		}
	}
	return 0;
}
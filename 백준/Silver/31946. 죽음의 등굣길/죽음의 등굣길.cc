#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void) // 기존 방식은 대각선을 못가네...
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0, x = 0;
	cin >> n >> m;
	vector<vector<int>>v(n, vector<int>(m, 0));
	vector<vector<int>>direction = { {-1,0},{1,0},{0,-1},{0,1} };
	vector<vector<bool>>visited(n, vector<bool>(m, false));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> v[i][j];
		}
	}
	cin >> x;
	queue<pii>q;
	q.push(make_pair(0, 0));
	visited[0][0] = true;
	while (!q.empty())
	{
		pii cur = q.front();
		q.pop();
		if (cur.first == n - 1 && cur.second == m - 1)
		{
			cout << "ALIVE";
			return 0;
		}
		map<pair<int, int>, int>temp; // 중복방문 될수도 그래서 map 썼는데 set쓰는게 더 편할지도.....
		queue<tuple<int, int, int>>dis;
		dis.push(make_tuple(cur.first, cur.second, 0));
		while (!dis.empty())
		{
			tuple c = dis.front();
			dis.pop();
			for (int i = 0; i < 4; ++i)
			{
				int nx = get<0>(c) + direction[i][0];
				int ny = get<1>(c) + direction[i][1];
				if (nx >= 0 && ny >= 0 && nx < n && ny < m)
				{
					if (!visited[nx][ny] && get<2>(c) < x)
					{
						dis.push(make_tuple(nx, ny, get<2>(c) + 1));
					}
				}
			}
			temp[make_pair(get<0>(c), get<1>(c))]++;
		}
		for (auto& i : temp)
		{
			if (!visited[i.first.first][i.first.second] && v[i.first.first][i.first.second] == v[0][0])
			{
				q.push(make_pair(i.first.first, i.first.second));
				visited[i.first.first][i.first.second] = true;
			}
		}
	}
	cout << "DEAD";
	return 0;
}
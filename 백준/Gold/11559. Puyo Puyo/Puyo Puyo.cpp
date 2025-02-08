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
	vector<vector<char>>v(12, vector<char>(6));
	vector<vector<bool>>visited(12, vector<bool>(6, false));
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	for (int i = 0; i < 12; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < 6; ++j)
		{
			v[i][j] = str[j];
		}
	}
	auto G = [&]
		{
			for (int i = 0; i < 6; ++i) // i열
			{
				pii pivot = make_pair(-1, -1);
				for (int j = 11; j >= 0; --j) // j 행
				{
					if (pivot == make_pair(-1, -1) && v[j][i] == '.')
					{
						pivot = make_pair(j, i);
					}
					if (pivot != make_pair(-1, -1) && v[j][i] != '.')
					{
						swap(v[j][i], v[pivot.first][pivot.second]);
						pivot = make_pair(pivot.first - 1, i);
					}
				}
			}
		};
	auto bfs = [&](int x, int y, char p)
		{
			int cnt = 1;
			vector<pii>temp;
			temp.push_back(make_pair(x, y));
			visited[x][y] = true;
			queue<pii>q;
			q.push(make_pair(x, y));
			while (!q.empty())
			{
				auto [a, b] = q.front();
				q.pop();
				for (int i = 0; i < 4; ++i)
				{
					int nx = a + dir[i][0];
					int ny = b + dir[i][1];
					if (nx >= 0 && nx < 12 && ny >= 0 && ny < 6)
					{
						if (!visited[nx][ny] && v[nx][ny] == p)
						{
							visited[nx][ny] = true;
							q.push(make_pair(nx, ny));
							temp.push_back(make_pair(nx, ny));
							cnt++;
						}
					}
				}
			}
			if (cnt >= 4)
			{
				for (auto& [i, j] : temp)
				{
					v[i][j] = '.';
				}
				return true;
			}
			return false;
		};
	auto get_h = [&]
		{
			int s = 0;
			for (int i = 0; i < 6; ++i)
			{
				int temp = 11;
				for (int j = 11; j >= 0; --j)
				{
					if (v[j][i] == '.')
					{
						temp = j;
						break;
					}
				}
				s = min(s, temp);
			}
			return s;
		};
	G();
	int ans = 0, h = get_h();
	while (1)
	{
		bool flag = false;
		for (int i = 0; i < 6; ++i)
		{
			for (int j = 11; j >= h; --j)
			{
				if (!visited[j][i] && v[j][i] != '.')
				{
					if (bfs(j, i, v[j][i]))
					{
						flag = true;
					}
				}
			}
		}
		if (!flag)
		{
			break;
		}
		ans++;
		vector<vector<bool>>(12, vector<bool>(6, false)).swap(visited);
		G();
		h = get_h();
	}
	cout << ans;
	return 0;
}
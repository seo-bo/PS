#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void) // 전략 - (아래 | 위) -> 돌맹이 / (왼쪽 | 오른쪽) -> 돌맹이 X
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int T = 0;
	cin >> T;
	if (T == 1)
	{
		int n = 0;
		cin >> n;
		queue<pii>q;
		vector<vector<int>>dir = { {-1,0},{1,0}, {0,-1},{0,1} }; // 아래, 위 / 왼쪽, 오른쪽
		vector<vector<char>>grid(n, vector<char>(n));
		vector<vector<bool>>visited(n, vector<bool>(n, false));
		for (int i = 0; i < n; ++i)
		{
			string str;
			cin >> str;
			for (int j = 0; j < n; ++j)
			{
				grid[i][j] = str[j];
				if (grid[i][j] == 'G')
				{
					q.push(make_pair(i, j));
					visited[i][j] = true;
				}
			}
		}
		while (!q.empty())
		{
			auto [x, y] = q.front();
			q.pop();
			for (int i = 0; i < 4; ++i)
			{
				int nx = x + dir[i][0];
				int ny = y + dir[i][1];
				if (nx >= 0 && nx < n && ny >= 0 && ny < n)
				{
					if (!visited[nx][ny] && grid[nx][ny] == '.')
					{
						if (i < 2)
						{
							grid[nx][ny] = 'S';
						}
						visited[nx][ny] = true;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
		for (auto& i : grid)
		{
			for (auto& j : i)
			{
				cout << j;
			}
			cout << endl;
		}
		cout.flush();
	}
	else if (T == 2) // 아래 먼저 / 오른쪽 먼저
	{
		char pre = 'X';
		int px = -1, py = -1;
		unordered_map<char, char>mm = { {'D','U'}, {'U','D'},{'L','R'},{'R','L'} };
		while (1)
		{
			int a = 0, b = 0, c = 0;
			cin >> a >> b >> c;
			if ((!a && !b && !c) || (a == -1 && b == -1 && c == -1))
			{
				exit(0);
			}
			if (pre == 'X') // 첫 이동
			{
				if (c) // 돌맹 있다 (위 , 아래)
				{
					pre = 'D';
					cout << 'D' << endl;
				}
				else // 돌맹 없다 (왼 ,오)
				{
					pre = 'R';
					cout << 'R' << endl;
				}
			}
			else if (c) // 돌맹 있다 (위, 아래)
			{
				if (px == a && py == b) // 부딪힌거야
				{
					pre = mm[pre];
					cout << pre << endl;
				}
				else
				{
					if (pre == 'L' || pre == 'R')
					{
						pre = 'D';
					}
					cout << pre << endl;
				}
			}
			else if (!c) // 돌맹 없다 (왼, 오)
			{
				if (px == a && py == b)
				{
					pre = mm[pre];
					cout << pre << endl;
				}
				else
				{
					if (pre == 'U' || pre == 'D')
					{
						pre = 'R';
					}
					cout << pre << endl;
				}
			}
			px = a, py = b;
			cout.flush();
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<vector<pii>, int>ti;
typedef tuple<pii, pii, int>tp;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<char>>grid(n, vector<char>(m));
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	vector<pii>coin;
	set<tp>visited;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; ++j)
		{
			grid[i][j] = str[j];
			if (str[j] == 'o')
			{
				coin.push_back(make_pair(i, j));
				grid[i][j] = '.';
			}
		}
	}
	queue<ti>q;
	q.push(make_tuple(coin, 0));
	visited.insert(make_tuple(coin[0], coin[1], 0));
	visited.insert(make_tuple(coin[1], coin[0], 0));
	while (!q.empty())
	{
		auto [co, cnt] = q.front();
		q.pop();
		if (cnt == 10)
		{
			continue;
		}
		for (int i = 0; i < 4; ++i)
		{
			vector<pii>temp = co;
			if (i == 0 && temp[1].first < temp[0].first)
			{
				swap(temp[0], temp[1]);
			}
			else if (i == 1 && temp[1].first > temp[0].first)
			{
				swap(temp[0], temp[1]);
			}
			else if (i == 2 && temp[1].second < temp[0].second)
			{
				swap(temp[0], temp[1]);
			}
			else if (i == 3 && temp[1].second > temp[0].second)
			{
				swap(temp[0], temp[1]);
			}
			int fre = 0;
			for (int j = 0; j < 2; ++j)
			{
				auto& [a, b] = temp[j];
				int nx = a + dir[i][0];
				int ny = b + dir[i][1];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m)
				{
					if ((a == temp[(j + 1) % 2].first && b == temp[(j + 1) % 2].second) || grid[nx][ny] == '#')
					{
						continue;
					}
					else
					{
						a = nx;
						b = ny;
					}
				}
				else
				{
					fre++;
					a = INT_MAX, b = INT_MAX;
				}
			}
			if (fre == 0 && visited.find(make_tuple(temp[0], temp[1], cnt + 1)) == visited.end())
			{
				visited.insert(make_tuple(temp[0], temp[1], cnt + 1));
				visited.insert(make_tuple(temp[1], temp[0], cnt + 1));
				q.push(make_pair(temp, cnt + 1));
			}
			else if (fre == 1)
			{
				cout << cnt + 1;
				return 0;
			}
		}
	}
	cout << -1;
	return 0;
}
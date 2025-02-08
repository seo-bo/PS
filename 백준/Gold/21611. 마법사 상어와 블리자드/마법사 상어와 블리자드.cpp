#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	int x = n / 2, y = n / 2;
	vector<vector<int>>v(n, vector<int>(n, 0));
	vector<vector<int>>dir1 = { {-1,0},{1,0},{0,-1},{0,1} };
	vector<vector<int>>dir2 = { {0,-1},{1,0},{0,1},{-1,0} };
	vector<int>ans(4);
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	auto move = [&]
		{
			int nx = x, ny = y;
			int d = 0;
			deque<pii>dq;
			for (int i = 0; i < 2 * n - 1; ++i)
			{
				int r = (i / 2) + 1;
				if (r == n)
				{
					r = n - 1;
				}
				for (int j = 0; j < r; ++j)
				{
					nx = nx + dir2[d][0], ny = ny + dir2[d][1];
					if (!v[nx][ny])
					{
						continue;
					}
					if (dq.empty() || dq.back().first != v[nx][ny])
					{
						dq.push_back(make_pair(v[nx][ny], 1));
					}
					else if (dq.back().first == v[nx][ny])
					{
						dq.back().second++;
					}
				}
				d = (d + 1) % 4;
			}
			bool flag = false;
			while (!flag)
			{
				flag = true;
				deque<pii>temp;
				for (auto& [a,b] : dq)
				{
					if (b >= 4)
					{
						ans[a] += b;
						flag = false;
					}
					else
					{
						if (temp.empty() || temp.back().first != a)
						{
							temp.push_back(make_pair(a, b));
						}
						else if(temp.back().first == a)
						{
							temp.back().second += b;
						}
					}
				}
				swap(dq, temp);
			}
			vector<vector<int>>(n, vector<int>(n, 0)).swap(v);
			deque<int>tt;
			for (auto& [a, b] : dq)
			{
				tt.push_back(b);
				tt.push_back(a);
			}
			nx = x, ny = y, d = 0;
			for (int i = 0; i < 2 * n - 1 && !tt.empty(); ++i)
			{
				int r = (i / 2) + 1;
				if (r == n)
				{
					r = n - 1;
				}
				for (int j = 0; j < r && !tt.empty(); ++j)
				{
					nx = nx + dir2[d][0], ny = ny + dir2[d][1];
					v[nx][ny] = tt.front();
					tt.pop_front();
				}
				d = (d + 1) % 4;
			}
		};
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		a--;
		int nx = x, ny = y;
		for (int j = 0; j < b; ++j)
		{
			nx = nx + dir1[a][0];
			ny = ny + dir1[a][1];
			v[nx][ny] = 0;
		}
		move();
	}
	ll res = 0;
	for (int i = 1; i <= 3; ++i)
	{
		res += i * ans[i];
	}
	cout << res;
	return 0;
}
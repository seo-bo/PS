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
	int n = 0;
	cin >> n;
	vector<unordered_set<int>>fre(n * n + 1);
	vector<vector<int>>grid(n, vector<int>(n, 0));
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	vector<int>order(n * n);
	for (int i = 0; i < n * n; ++i)
	{
		cin >> order[i];
		for (int j = 0; j < 4; ++j)
		{
			int a = 0;
			cin >> a;
			fre[order[i]].insert(a);
		}
	}
	for (auto& _ : order)
	{
		tuple<int, int, int, int> pos = make_tuple(-1, -1, -1, -1); // x , y , 좋아하는 학생, 빈칸
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (grid[i][j])
				{
					continue;
				}
				int empty = 0, pivot = 0;
				for (int k = 0; k < 4; ++k)
				{
					int nx = i + dir[k][0];
					int ny = j + dir[k][1];
					if (nx >= 0 && nx < n && ny >= 0 && ny < n)
					{
						if (!grid[nx][ny])
						{
							empty++;
						}
						else if (fre[_].find(grid[nx][ny]) != fre[_].end())
						{
							pivot++;
						}
					}
				}
				auto [a, b, c, d] = pos;
				if (pivot > c || (pivot == c && empty > d))
				{
					pos = make_tuple(i, j, pivot, empty);
				}
			}
		}
		auto [a, b, c, d] = pos;
		grid[a][b] = _;
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int p = grid[i][j], cnt = 0;
			for (int k = 0; k < 4; ++k)
			{
				int nx = i + dir[k][0];
				int ny = j + dir[k][1];
				if (nx >= 0 && nx < n && ny >= 0 && ny < n)
				{
					if (fre[p].find(grid[nx][ny]) != fre[p].end())
					{
						cnt++;
					}
				}
			}
			ans += ll(pow(10, cnt - 1));
		}
	}
	cout << ans;
	return 0;
}
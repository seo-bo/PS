#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<vector<int>>v(19, vector<int>(19, 0));
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	vector<vector<int>>dir = { {-1,0},{0,1},{1,1},{1,-1} };
	auto judge = [&](int x, int y)
		{
			int pivot = v[x][y];
			for (int i = 0; i < 4; ++i)
			{
				int cnt = 1;
				int nx = x + dir[i][0];
				int ny = y + dir[i][1];
				while ((nx >= 0 && nx < 19 && ny >= 0 && ny < 19) && pivot == v[nx][ny])
				{
					cnt++;
					nx = nx + dir[i][0];
					ny = ny + dir[i][1];
				}
				nx = x - dir[i][0];
				ny = y - dir[i][1];
				while ((nx >= 0 && nx < 19 && ny >= 0 && ny < 19) && pivot == v[nx][ny])
				{
					cnt++;
					nx = nx - dir[i][0];
					ny = ny - dir[i][1];
				}
				if (cnt == 5)
				{
					return true;
				}
			}
			return false;
		};
	for (int i = 0; i < 19; ++i)
	{
		for (int j = 0; j < 19; ++j)
		{
			if (v[j][i] && judge(j, i))
			{
				cout << v[j][i] << '\n';
				cout << j + 1 << ' ' << i + 1;
				return 0;
			}
		}
	}
	cout << 0;
	return 0;
}
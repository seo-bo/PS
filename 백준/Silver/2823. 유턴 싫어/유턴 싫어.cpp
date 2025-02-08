#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

int direction[4][2] = { {-1,0},{1,0},{0,-1},{0,1} }; // 갈수있는게 한개 이하의 경로라면, 유턴할수밖에 없지않나?
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int row = 0, col = 0;
	cin >> row >> col;
	string grid[10];
	for (int i = 0; i < row; ++i)
	{
		cin >> grid[i];
	}
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (grid[i][j] == '.')
			{
				int cnt = 0;
				for (int k = 0; k < 4; ++k)
				{
					int nx = i + direction[k][0];
					int ny = j + direction[k][1];
					if (nx >= 0 && nx < row && ny >= 0 && ny < col && grid[nx][ny] == '.')
					{
						cnt++;
					}
				}
				if (cnt <= 1)
				{
					cout << 1;
					return 0;
				}
			}
		}
	}
	cout << 0;
	return 0;
}
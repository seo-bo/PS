#include <bits/stdc++.h>
using namespace std;
//단순 dfs 돌리면 시간초과날듯? 500*500*500*500!?

int mapp[501][501] = { 0, };
int dp[501][501] = { 0, };
int direction[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int num = 0;

int dfs(int x, int y)
{
	if (dp[x][y] != 0) // dp배열이 visited 역할도 함
	{
		return dp[x][y]; // 이미 지나간 자리면 메모이제이션을 하자
	}
	dp[x][y] = 1; // 일단 하나는 먹었다?
	for (int i = 0; i < 4; ++i) // 상 하 좌 우 이동
	{
		int nx = x + direction[i][0];
		int ny = y + direction[i][1];
		if (nx >= 0 && nx < num && ny >= 0 && ny < num)
		{
			if (mapp[x][y] < mapp[nx][ny]) // 이동했을때 더 큰걸 먹자
			{
				dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1); // 하나 먹기 + 새 좌표로 갈수있는곳 까지 (미로 탐색 비슷)
			}
		}
	}
	return dp[x][y];
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int result = 0;
	cin >> num;
	for (int i = 0; i < num; ++i)
	{
		for (int j = 0; j < num; ++j)
		{
			cin >> mapp[i][j];
		}
	}
	for (int i = 0; i < num; ++i)
	{
		for (int j = 0; j < num; ++j)
		{
			result = max(result, dfs(i, j));
		}
	}
	cout << result;
	return 0;
}
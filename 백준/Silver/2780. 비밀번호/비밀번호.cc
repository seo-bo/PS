#include <bits/stdc++.h>
#include <unordered_map>
#define MOD 1234567
using namespace std;
typedef long long ll;
typedef long double lb;

int grid[4][3] = { {1,2,3}, {4,5,6},{7,8,9},{0,-1,-1} };
int direction[4][2] = { {-1,0},{1,0},{0,-1},{0,1}};
vector<int>password[10];
ll dp[1001][11] = { 0, };

void input()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (grid[i][j] != -1)
			{
				for (int k = 0; k < 4; ++k)
				{
					int nx = i + direction[k][0];
					int ny = j + direction[k][1];
					if (nx >= 0 && nx < 4 && ny >= 0 && ny < 3)
					{
						if (grid[nx][ny] != -1)
						{
							password[grid[i][j]].push_back(grid[nx][ny]);
						}
					}
				}
			}
		}
	}
	for (int i = 0; i <= 9; ++i)
	{
		dp[1][i] = 1;
		dp[1][10] += dp[1][i];
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	int T = 0;
	cin >> T;
	for (int i = 2; i <= 1000; ++i)
	{
		for (int j = 0; j <= 9; ++j)
		{
			for (auto& k : password[j])
			{
				dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
			}
			dp[i][10] = (dp[i][10] + dp[i][j]) % MOD;
		}
	}
	while (T--)
	{
		int N = 0;
		cin >> N;
		cout << dp[N][10] << "\n";
	}
	return 0;
}
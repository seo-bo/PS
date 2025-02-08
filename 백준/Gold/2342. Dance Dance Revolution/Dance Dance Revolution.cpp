#include <bits/stdc++.h>
#define INF 999999999
using namespace std;
int movee[5][5] = { {1,2,2,2,2},{INF,1,3,4,3},{INF,3,1,3,4},{INF,4,3,1,3},{INF,3,4,3,1} }; // from ~ to 표
int ary[100001] = { 0, };
int dp[5][5][100001] = { 0, };
// 왼발 , 오른발, 횟수

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int count = 0, result = INF;
	for (int i = 1; i <= 100001; ++i)
	{
		int temp = 0;
		cin >> temp;
		if (temp == 0)
		{
			break;
		}
		count++;
		ary[i] = temp;
	}
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			for (int k = 0; k < 100001; ++k)
			{
				dp[i][j][k] = INF;
			}
		}
	}
	dp[0][0][0] = 0;
	for (int i = 1; i <= count; ++i) // 완전 탐색하기
	{
		for (int j = 0; j < 5; ++j) // 왼발
		{
			for (int k = 0; k < 5; ++k) // 오른발
			{
				dp[ary[i]][k][i] = min(dp[ary[i]][k][i], dp[j][k][i - 1] + movee[j][ary[i]]);
				dp[j][ary[i]][i] = min(dp[j][ary[i]][i], dp[j][k][i - 1] + movee[k][ary[i]]);
			}
		}
	}
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			result = min(result, dp[i][j][count]);
		}
	}
	cout << result;
	return 0;
}
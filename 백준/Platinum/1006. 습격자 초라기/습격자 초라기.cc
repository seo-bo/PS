#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;

int ary[10001][2] = { 0, };
int dp[10001][3] = { 0, };
int N = 0, W = 0;

void check(int num)
{
	for (int i = num; i < N; ++i)
	{
		dp[i + 1][0] = min(dp[i][1] + 1, dp[i][2] + 1);
		if (ary[i][0] + ary[i][1] <= W) // 위 아래를 하나로 묶을 수 있다면?
		{
			dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + 1); // 그냥 하나로 취급하자
		}
		if (i > 0 && ary[i - 1][0] + ary[i][0] <= W && ary[i - 1][1] + ary[i][1] <= W) // 두 행다 왼쪽 오른쪽 묶을 수 있다면?
		{
			dp[i + 1][0] = min(dp[i + 1][0], dp[i - 1][0] + 2); // 하나씩 있는거로 취급하자
		}
		if (i < N - 1) // 여유공간이 하나이상 남아야 case2와 case3도 사용가능
		{
			dp[i + 1][1] = dp[i + 1][0] + 1; // 아래행에 하나 준다고 생각하고
			if (ary[i][0] + ary[i + 1][0] <= W) // 만약 줬는데 윗행 왼쪽 오른쪽 묶을 수 있다면?
			{
				dp[i + 1][1] = min(dp[i + 1][1], dp[i][2] + 1); // 비교해서 작은거
			}
			dp[i + 1][2] = dp[i + 1][0] + 1; // 윗행에 하나 준다고 생각하고
			if (ary[i][1] + ary[i + 1][1] <= W) // 만약 줬는데 아래행 왼쪽 오른쪽 묶을 수 있다면?
			{
				dp[i + 1][2] = min(dp[i + 1][2], dp[i][1] + 1); // 비교해서 작은거
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int test = 0;
	cin >> test;
	while (test--)
	{
		int result = INF;
		cin >> N >> W;
		for (int i = 0; i < N; ++i)
		{
			cin >> ary[i][0];
		}
		for (int i = 0; i < N; ++i)
		{
			cin >> ary[i][1];
		}
		dp[0][1] = dp[0][2] = 1;
		check(0);
		result = min(result, dp[N][0]);
		if (N > 1)
		{
			if (ary[0][0] + ary[N - 1][0] <= W) // 원형이니 처음일때 왼쪽거도 비교(윗 행)
			{
				dp[1][0] = 1;
				dp[1][1] = 2;
				dp[1][2] = (ary[0][1] + ary[1][1] <= W) ? 1 : 2; //묶이면 하나고 안묶이면 둘
				check(1);
				result = min(result, dp[N - 1][2] + 1); // 위 하나 채운거랑 비교
			}
			if (ary[0][1] + ary[N - 1][1] <= W) // 원형이니 처음일때 왼쪽거도 비교(아래 행)
			{
				dp[1][0] = 1;
				dp[1][1] = (ary[0][0] + ary[1][0] <= W) ? 1 : 2; //묶이면 하나고 안묶이면 둘
				dp[1][2] = 2;
				check(1);
				result = min(result, dp[N - 1][1] + 1);
			}
			if (ary[0][0] + ary[N - 1][0] <= W && ary[0][1] + ary[N - 1][1] <= W) // 원형이니 처음일때 왼쪽거도 비교(둘 다)
			{
				dp[1][0] = 0;
				dp[1][1] = dp[1][2] = 1;
				check(1);
				result = min(result, dp[N - 1][0] + 2); // 두 열 채워준거랑 비교
			}
		}
		cout << result << "\n";
	}
	return 0;
}
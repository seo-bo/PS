#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

lb dp[101][2] = { 0, };

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N = 0, now = 0;
	cin >> N >> now;
	vector<lb>v(5);// 좋-좋 / 좋-실 / 실-좋 / 실-실
	for (int i = 1; i <= 4; ++i)
	{
		cin >> v[i];
	}
	dp[0][now] = 1;
	for (int i = 1; i <= N; ++i) // 0은 좋고, 1은 나쁜
	{
		dp[i][0] = (dp[i - 1][0] * v[1]) + (dp[i - 1][1] * v[3]);
		dp[i][1] = (dp[i - 1][0] * v[2]) + (dp[i - 1][1] * v[4]);
	}
	cout << fixed << setprecision(0) << round(dp[N][0] * 1000) << "\n";
	cout << fixed << setprecision(0) << round(dp[N][1] * 1000);
	return 0;
}

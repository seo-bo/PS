#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

int dp[(1 << 18) + 1] = { 0, };
int a[20] = { 0, }, b[20] = { 0, };
int N = 0;

int solve(int num)
{
	if (dp[num] != -1)
	{
		return dp[num];
	}
	dp[num] = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = i + 1; j < N; ++j)
		{
			if ((num & (1 << i)) && (num & (1 << j)) && (a[i] == a[j] || b[i] == b[j]))
			{
				if (!solve(num ^ (1 << i) ^ (1 << j)))
				{
					dp[num] = 1;
					return 1;
				}
			}
		}
	}
	return dp[num];
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> a[i] >> b[i];
	}
	memset(dp, -1, sizeof(dp));
	int result = solve((1 << N) - 1);
	if (result == 1)
	{
		cout << "Takahashi";
	}
	else
	{
		cout << "Aoki";
	}

	return 0;
}

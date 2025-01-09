#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

ll ary[5005][5005] = { 0, };
ll dp[5005][5005] = { 0, };

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N = 0, T = 0;
	string str;
	cin >> N >> str >> T;
	for (int i = 0; i < N; ++i)
	{
		for (int j = i + 1; j < N; ++j)
		{
			int k = j - i - 1;
			if (i % 2)
			{
				dp[k][j] = max(dp[k + 1][j], dp[k][j - 1]);
			}
			else
			{
				ary[k][j] = ary[k + 1][j - 1] + (str[k] == str[j]);
				dp[k][j] = max({ ary[k][j], dp[k][j - 1], dp[k + 1][j] });
			}
		}
	}
	for (int i = 0; i < T; ++i)
	{
		int start = 0, end = 0;
		cin >> start >> end;
		start--; end--;
		cout << dp[start][end] << "\n";
	}
	return 0;
}
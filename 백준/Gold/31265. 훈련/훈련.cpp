#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

vector<int>v[1005];
vector<int>g;
bool dp[1005][10005]; // 몇번째 훈련 / 시간

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll sum = 0;
	int N = 0, M = 0; // M = 최대 훈련시간
	cin >> N >> M;
	g.resize(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> g[i];
	}
	for (int i = 1; i <= N; ++i)
	{
		int temp = 0;
		int MIN = INT_MAX;
		for (int k = 0; k < g[i - 1]; ++k)
		{
			cin >> temp;
			v[i].push_back(temp);
			MIN = min(MIN, temp);
		}
		sum += MIN;
	}
	if (sum > M)
	{
		cout << -1;
		return 0;
	}
	if (sum == M)
	{
		cout << sum;
		return 0;
	}
	dp[0][0] = true;
	int cnt = 0;
	for (int i = 1; i <= N; ++i)  // N번째 훈련
	{
		for (auto& j : v[i]) // 훈련 정보
		{
			vector<int>t;
			for (int k = 0; k <= M; ++k) // 시간 정보
			{
				if (k - j >= 0 && (dp[i][k - j] || dp[i - 1][k - j]) && !dp[i][k])
				{
					t.push_back(k);
				}
			}
			for (auto& z : t)
			{
				dp[i][z] = true;
			}
		}
	}
	ll result = 0;
	for (ll i = 1; i <= M; ++i)
	{
		if (dp[N][i])
		{
			result = max(result, i);
		}
	}
	cout << result;
}
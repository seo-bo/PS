#include <bits/stdc++.h>
#include <unordered_map>
#define INF 2000000000
using namespace std;
typedef long long ll;

ll dp[1300] = { 0, }; // 목표점에 도달한게 최대값이 아닐수도있다는거임?

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c = 0, n = 0;
	cin >> c >> n;
	for (int i = 0; i < c + 150; ++i)
	{
		dp[i] = INF;
	}
	dp[0] = 0;
	vector<pair<ll, ll>>ary(n, { 0,0 });
	for (int i = 0; i < n; ++i)
	{
		cin >> ary[i].first >> ary[i].second; // 비용, 고객수
	}
	for (auto& k : ary)
	{
		for (int i = k.second; i < c + 150; ++i)
		{
			dp[i] = min(dp[i], dp[i - k.second] + k.first);
		}
	}
	ll result = dp[c];
	for (int i = c; i < c + 150; ++i)
	{
		result = min(result, dp[i]);
	}
	cout << result;
	return 0;
}
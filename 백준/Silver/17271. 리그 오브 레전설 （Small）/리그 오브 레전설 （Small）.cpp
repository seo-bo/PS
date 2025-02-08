#include <bits/stdc++.h>
#include <unordered_map>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef long double lb;

ll dp[10001] = {0,};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N =0, M =0;
	cin >> N >> M;
	dp[0] = 1;
	for (int i =1; i<=N;++i)
	{
		dp[i] = dp[i-1];
		if(i - M >=0)
		{
			dp[i] = (dp[i-1] + dp[i-M])%MOD;
		}
	}
	cout << dp[N];
	return 0;
}

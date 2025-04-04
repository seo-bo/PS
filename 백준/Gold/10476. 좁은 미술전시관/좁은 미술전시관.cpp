#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n =0, k = 0,sum = 0;
	cin >> n >> k;
	vector<vector<int>>v(n+1,vector<int>(3,0));
	for(int i =1; i<=n;++i)
	{
		for(int j =1; j<=2;++j)
		{
			cin >> v[i][j];
			sum += v[i][j];
		}
	}
	vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(3,vector<int>(k+1,-1)));
	function<int(int,int,int)> dfs = [&] (int x, int ok,int cnt)
	{
		if(cnt == k)
		{
			return 0;
		}
		if(x > n)
		{
			return (int)1e7;
		}
		if(dp[x][ok][cnt] != -1)
		{
			return dp[x][ok][cnt];
		}
		int res = dfs(x+1,0,cnt);
		if(ok != 1)
		{
			res = min(res,dfs(x+1,2,cnt+1) + v[x][2]);
		}
		if(ok != 2)
		{
			res = min(res,dfs(x+1,1,cnt+1) + v[x][1]);
		}
		return dp[x][ok][cnt] = res;
	};
	cout << sum - dfs(1,0,0);
	return 0;
}

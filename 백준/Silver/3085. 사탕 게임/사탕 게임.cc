#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<vector<char>>v(n, vector<char>(n));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> v[i][j];
		}
	}
	ll ans = 0;
	auto check = [&]()
		{
			ll ans = 1;	
			for (int i = 0; i < n; ++i)
			{
				ll temp = 1;
				for (int j = 1; j < n; ++j)
				{
					if (v[i][j - 1] != v[i][j])
					{
						temp = 1;
					}
					else
					{
						temp++;
					}
					ans = max(ans, temp);
				}
			}
			for (int i = 0; i < n; ++i) 
			{
				ll temp = 1;
				for (int j = 1; j < n; ++j)
				{
					if (v[j - 1][i] != v[j][i])
					{
						temp = 1;
					}
					else
					{
						temp++;
					}
					ans = max(ans, temp);
				}
			}
			return ans;
		};
	vector<vector<int>>dir = { {0,1},{1,0} };
	for (int i = 0; i < n; ++i) 
	{
		for (int j = 0; j < n; ++j) 
		{
			for (int d = 0; d < 2; ++d) 
			{
				int nx = i + dir[d][0];
				int ny = j + dir[d][1];
				if (nx < n && ny < n && v[i][j] != v[nx][ny])
				{
					swap(v[i][j], v[nx][ny]);
					ans = max(ans, check());
					swap(v[i][j], v[nx][ny]);
				}
			}
		}
	}
	cout << ans;
	return 0;
}
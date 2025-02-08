#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	vector<vector<int>>v(105, vector<int>(105, 0));
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		for (int i = a; i < a + 10; ++i)
		{
			for (int j = b; j < b + 10; ++j)
			{
				v[i][j] = 1;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 105; ++i)
	{
		for (int j = 0; j < 105; ++j)
		{
			if (v[i][j])
			{
				for (int k = 0; k < 4; ++k)
				{
					int nx = i + dir[k][0];
					int ny = j + dir[k][1];
					if (!v[nx][ny])
					{
						ans++;
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}
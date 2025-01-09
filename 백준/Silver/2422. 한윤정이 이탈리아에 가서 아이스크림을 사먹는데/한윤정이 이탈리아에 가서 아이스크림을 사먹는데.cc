#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0, ans = 0;
	cin >> n >> m;
	vector<vector<bool>>v(201, vector<bool>(201));
	for (int i = 0; i < m; ++i)
	{
		int left = 0, right = 0;
		cin >> left >> right;
		v[left][right] = 1;
		v[right][left] = 1;
	}
	vector<int>t;
	function<void(int, int)> dfs = [&](int start, int depth) ->void
		{
			if (depth == 3)
			{
				ans++;
				return;
			}
			for (int i = start; i <= n; ++i)
			{
				bool check = true;
				for (auto& k : t)
				{
					if (v[k][i])
					{
						check = false;
						break;
					}
				}
				if (check)
				{
					t.push_back(i);
					dfs(i + 1, depth + 1);
					t.pop_back();
				}
			}
		};
	dfs(1, 0);
	cout << ans;
	return 0;
}
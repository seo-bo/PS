#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void) // 그냥 다익스트라 돌리면 안되나?
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<int>v(n);
	vector<int>oper(4);
	for (auto& i : v)
	{
		cin >> i;
	}
	for (int i = 0; i < 4; ++i)
	{
		cin >> oper[i];
	}
	int mini = INT_MAX, maxi = -INT_MAX;
	function<void(int, int)> dfs = [&](int depth, int sum) ->void
		{
			if (depth == n)
			{
				mini = min(sum, mini);
				maxi = max(sum, maxi);
				return;
			}
			for (int i = 0; i < 4; ++i)
			{
				if (oper[i])
				{
					oper[i]--;
					if (i == 0)
					{
						dfs(depth + 1, sum + v[depth]);
					}
					else if (i == 1)
					{
						dfs(depth + 1, sum - v[depth]);
					}
					else if (i == 2)
					{
						dfs(depth + 1, sum * v[depth]);
					}
					else
					{
						dfs(depth + 1, sum / v[depth]);
					}
					oper[i]++;
				}
			}
		};
	dfs(1, v[0]);
	cout << maxi << '\n';
	cout << mini;
	return 0;
}
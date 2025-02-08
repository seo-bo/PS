#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	while (1) // 마지막 수 -> 바닥
	{
		vector<vector<vector<int>>>v(6);
		for (int i = 0; i < 6; ++i)
		{
			vector<int>t1(3, 0), t2(3, 0), t3(3, 0);
			for (int j = 0; j < 3; ++j)
			{
				int temp = 0;
				cin >> temp;
				t1[j] = temp;
				t2[(j + 1) % 3] = temp;
				t3[(j + 2) % 3] = temp;
			}
			v[i].push_back(t1);
			v[i].push_back(t2);
			v[i].push_back(t3);
		}
		vector<pii>temp;
		int ans = 0;
		function<void(int, int, int)> dfs = [&](int mask, int depth, int sum)
			{
				if (depth == 6)
				{
					if (temp[0].second == temp.back().first)
					{
						ans = max(ans, sum);
					}
					return;
				}
				for (int j = 0; j < 6; ++j)
				{
					if (mask & (1 << j))
					{
						continue;
					}
					for (int i = 0; i < 3; ++i)
					{
						if (depth > 0 && v[j][i][1] != temp.back().first)
						{
							continue;
						}
						temp.push_back(make_pair(v[j][i][0], v[j][i][1]));
						dfs(mask | (1 << j), depth + 1, sum + v[j][i][2]);
						temp.pop_back();
					}
				}
			};
		dfs(0, 0, 0);
		if (ans == 0)
		{
			cout << "none" << '\n';
		}
		else
		{
			cout << ans << '\n';
		}
		char p;
		cin >> p;
		if (p == '$')
		{
			break;
		}
	}
	return 0;
}
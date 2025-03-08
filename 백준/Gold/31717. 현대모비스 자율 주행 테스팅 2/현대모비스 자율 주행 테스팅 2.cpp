#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	vector<bool>ban(n + 1, false);
	vector<int>v(k);
	for (auto& i : v)
	{
		cin >> i;
	}
	vector<vector<vector<char>>>base(n + 1, vector<vector<char>>(2));
	vector<vector<int>>dir = { {-1,-1},{-1,1},{1,-1},{1,1},{1,0},{-1,0} };
	auto check = [&](int idx)
		{
			vector<int>per;
			auto& ok = base[idx];
			int len = ok[0].size();
			for (int j = 0; j < len; ++j)
			{
				for (int i = 0; i < 2; ++i)
				{
					if (ok[i][j] == '.')
					{
						continue;
					}
					for (int z = 0; z < 6; ++z)
					{
						int nx = i + dir[z][0];
						int ny = j + dir[z][1];
						if (nx >= 0 && nx < 2 && ny >= 0 && ny < len)
						{
							if (ok[nx][ny] == '#')
							{
								ban[idx] = true;
								per.clear();
								return per;
							}
						}
					}
					per.push_back(i);
				}
			}
			return per;
		};
	auto cal = [&](int a, int b)
		{
			if (a == -1)
			{
				return true;
			}
			auto& A = base[a];
			auto& B = base[b];
			int len = A[0].size() - 1;
			vector<vector<char>>ok = { {A[0][len],B[0][0]},{A[1][len],B[1][0]} };
			for (int i = 0; i < 2; ++i)
			{
				for (int j = 0; j < 2; ++j)
				{
					if (ok[i][j] == '.')
					{
						continue;
					}
					for (int z = 0; z < 6; ++z)
					{
						int nx = i + dir[z][0];
						int ny = j + dir[z][1];
						if (nx >= 0 && nx < 2 && ny >= 0 && ny < 2)
						{
							if (ok[nx][ny] == '#')
							{
								return false;
							}
						}
					}
				}
			}
			return true;
		};
	int idx = 1, pp = 0;
	for (int i = 0; i < 2 * n; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < (int)str.size(); ++j)
		{
			base[idx][pp].push_back(str[j]);
		}
		pp = (pp + 1) % 2;
		if (pp == 0)
		{
			idx++;
		}
	}
	vector<vector<int>>per(n + 1);
	vector<int>sum(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		per[i] = check(i);
		if (per[i].empty())
		{
			continue;
		}
		int pre = per[i][0], temp = 0;
		for (auto& j : per[i])
		{
			if (pre != j)
			{
				pre = j;
				temp++;
			}
		}
		sum[i] = temp;
	}
	ll ans = 0, pre = -1, pv = -1;
	for (auto& i : v)
	{
		if (ban[i])
		{
			cout << -1;
			return 0;
		}
		if (!cal(pre, i))
		{
			cout << -1;
			return 0;
		}
		ans += (ll)base[i][0].size();
		if (pre == -1 || pv == -1 || per[i].empty())
		{
			ans += sum[i];
		}
		else
		{
			ans += sum[i] + (pv != per[i].front());
		}
		if (!per[i].empty())
		{
			pv = per[i].back();
		}
		pre = i;
	}
	cout << ans - 1;
	return 0;
}
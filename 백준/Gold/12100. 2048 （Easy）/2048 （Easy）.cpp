#include <bits/stdc++.h>
#define OFF 1000
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<vector<int>>v(n, vector<int>(n, 0));
	for (auto& i : v)
	{
		for (auto& j : i)
		{
			cin >> j;
		}
	}
	int ans = 0;
	auto move = [&](int d, vector<vector<int>>pivot)
		{
			vector<vector<int>>temp(n, vector<int>(n, 0));
			if (d == 1)
			{
				for (int i = 0; i < n; ++i)
				{
					int idx = 0;
					vector<int>dq;
					for (int j = 0; j < n; ++j)
					{
						if (pivot[j][i])
						{
							dq.push_back(pivot[j][i]);
						}
					}
					for (int j = 0; j < dq.size(); ++j)
					{
						if (j < dq.size() - 1 && dq[j] == dq[j + 1])
						{
							temp[idx++][i] = dq[j] + dq[j + 1];
							++j;
						}
						else
						{
							temp[idx++][i] = dq[j];
						}
					}
				}
			}
			else if (d == 2)
			{
				for (int i = 0; i < n; ++i)
				{
					int idx = 0;
					vector<int>dq;
					for (int j = 0; j < n; ++j)
					{
						if (pivot[i][j])
						{
							dq.push_back(pivot[i][j]);
						}
					}
					for (int j = 0; j < dq.size(); ++j)
					{
						if (j < dq.size() - 1 && dq[j] == dq[j + 1])
						{
							temp[i][idx++] = dq[j] + dq[j + 1];
							++j;
						}
						else
						{
							temp[i][idx++] = dq[j];
						}
					}
				}
			}
			else if (d == 3)
			{
				for (int i = 0; i < n; ++i)
				{
					int idx = n - 1;
					vector<int>dq;
					for (int j = n - 1; j >= 0; --j)
					{
						if (pivot[j][i])
						{
							dq.push_back(pivot[j][i]);
						}
					}
					for (int j = 0; j < dq.size(); ++j)
					{
						if (j < dq.size() - 1 && dq[j] == dq[j + 1])
						{
							temp[idx--][i] = dq[j] + dq[j + 1];
							++j;
						}
						else
						{
							temp[idx--][i] = dq[j];
						}
					}
				}
			}
			else
			{
				for (int i = 0; i < n; ++i)
				{
					int idx = n - 1;
					vector<int>dq;
					for (int j = n - 1; j >= 0; --j)
					{
						if (pivot[i][j])
						{
							dq.push_back(pivot[i][j]);
						}
					}
					for (int j = 0; j < dq.size(); ++j)
					{
						if (j < dq.size() - 1 && dq[j] == dq[j + 1])
						{
							temp[i][idx--] = dq[j] + dq[j + 1];
							++j;
						}
						else
						{
							temp[i][idx--] = dq[j];
						}
					}
				}
			}
			return temp;
		};
	function<void(int, vector<vector<int>>)> dfs = [&](int depth, vector<vector<int>> pivot)
		{
			if (depth == 5)
			{
				for (int i = 0; i < n; ++i)
				{
					for (int j = 0; j < n; ++j)
					{
						ans = max(ans, pivot[i][j]);
					}
				}
				return;
			}
			for (int i = 1; i <= 4; ++i)
			{
				dfs(depth + 1, move(i, pivot));
			}
		};
	dfs(0, v);
	cout << ans;
	return 0;
}
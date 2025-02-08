#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef long double lb;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		vector<int>pre(n), in(n);
		vector<int>idx(n + 1, 0);
		for (auto& i : pre)
		{
			cin >> i;
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> in[i];
			idx[in[i]] = i;
		}
		function<void(int, int, int)> dfs = [&](int pst, int inst, int ined)
			{
				if (inst > ined)
				{
					return;
				}
				int node = pre[pst];
				int pos = idx[node];
				dfs(pst + 1, inst, pos - 1);
				dfs(pst + 1 + (pos - inst), pos + 1, ined);
				cout << node << ' ';
			};
		dfs(0, 0, n - 1);
		cout << '\n';
	}
	return 0;
}
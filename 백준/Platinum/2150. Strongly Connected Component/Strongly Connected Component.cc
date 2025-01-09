#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, e = 0, cnt = 0;
	cin >> n >> e;
	vector<vector<int>>graph(n + 1), ans;
	vector<int>num(n + 1, 0), low(n + 1, 0), S;
	vector<bool>in(n + 1, false);
	for (int i = 0; i < e; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
	}
	function<void(int)> scc = [&](int node)
		{
			num[node] = low[node] = ++cnt;
			S.push_back(node);
			in[node] = true;
			for (auto& i : graph[node])
			{
				if (!num[i])
				{
					scc(i);
					low[node] = min(low[node], low[i]);
				}
				else if (in[i])
				{
					low[node] = min(low[node], num[i]);
				}
			}
			if (low[node] == num[node])
			{
				vector<int>temp;
				while (1)
				{
					int a = S.back();
					in[a] = false;
					temp.push_back(a);
					S.pop_back();
					if (a == node)
					{
						break;
					}
				}
				sort(temp.begin(), temp.end());
				ans.push_back(temp);
			}
		};
	for (int i = 1; i <= n; ++i)
	{
		if (!num[i])
		{
			scc(i);
		}
	}
	cout << ans.size() << '\n';
	sort(ans.begin(), ans.end());
	for (auto& i : ans)
	{
		for (auto& j : i)
		{
			cout << j << ' ';
		}
		cout << -1 << '\n';
	}
	return 0;
}
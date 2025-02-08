#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		vector<int>in(n + 1, 0);
		vector<vector<int>>graph(n + 1);
		for (int i = 1; i <= n; ++i)
		{
			int a = 0;
			cin >> a;
			graph[i].push_back(a);
			in[a]++;
		}
		int ans = 0;
		queue<int>q;
		for (int i = 1; i <= n; ++i)
		{
			if (!in[i])
			{
				q.push(i);
			}
		}
		while (!q.empty())
		{
			int a = q.front();
			q.pop();
			ans++;
			for (auto& i : graph[a])
			{
				if (!(--in[i]))
				{
					q.push(i);
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
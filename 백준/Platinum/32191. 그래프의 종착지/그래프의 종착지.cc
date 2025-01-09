#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
typedef tuple<int, int, bool>tp;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, k = 0, t = 0;
	cin >> n >> k >> t;
	vector<pii>temp(k);
	vector<vector<pii>>graph(n + 1);
	vector<int>in(n + 1, 0), grade(n + 1, 0), f(n + 1, 0);
	vector<vector<int>>dp(n + 1);
	vector<bool>visited(n + 1, false);
	for (auto& [i, j] : temp)
	{
		cin >> i >> j;
	}
	int start = 0, pivot = 0;
	for (int i = 1; i <= n; ++i)
	{
		cin >> grade[i];
		if (grade[i] == 1)
		{
			start = i;
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >> f[i];
	}
	for (auto& [x, y] : temp)
	{
		if (x == -1 || y == -1)
		{
			continue;
		}
		pii _;
		if (grade[x] < grade[y])
		{
			if (f[x] == y)
			{
				_ = make_pair(y, 0);
			}
			else if (f[x] < y)
			{
				_ = make_pair(y, 1);
			}
			else
			{
				_ = make_pair(y, 2);
			}
			graph[x].push_back(_);
		}
		else
		{
			if (f[y] == x)
			{
				_ = make_pair(x, 0);
			}
			else if (f[y] < x)
			{
				_ = make_pair(x, 1);
			}
			else
			{
				_ = make_pair(x, 2);
			}
			graph[y].push_back(_);
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		sort(graph[i].begin(), graph[i].end(), [&](const pii& a, const pii& b)
			{
				if (a.second == b.second)
				{
					return a.first < b.first;
				}
				return a.second < b.second;
			});
	}
	queue<int>q;
	q.push(start);
	while (!q.empty())
	{
		int a = q.front();
		q.pop();
		for (auto& [i, __] : graph[a])
		{
			if (!visited[i])
			{
				visited[i] = true;
				q.push(i);
			}
			dp[a].push_back(i);
		}
	}
	vector<int>tt(n + 1, 0);
	tt[start] = t;
	int ans = 0;
	vector<bool>flag(n + 1, false);
	flag[start] = true;
	priority_queue<pii, vector<pii>, greater<pii>>pq;
	pq.push(make_pair(grade[start], start));
	while (!pq.empty())
	{
		auto [w, node] = pq.top();
		pq.pop();
		if (dp[node].empty())
		{
			if (flag[node])
			{
				ans = node;
			}
			continue;
		}
		if (!tt[node])
		{
			continue;
		}
		int pivot = tt[node] / dp[node].size(), exp = tt[node] % dp[node].size();
		//cout << node << ' ' << pivot << ' ' << exp << '\n';
		if (!pivot)
		{
			if (!exp)
			{
				int _ = dp[node].back();
				if (flag[node])
				{
					flag[_] = true;
				}
				pq.push(make_pair(grade[_], _));
				continue;
			}
			for (auto& i : dp[node])
			{
				tt[i] += (tt[node] ? 1 : 0);
				tt[node] = (0, tt[node] - 1);
				pq.push(make_pair(grade[i], i));
				if (!tt[node])
				{
					if (flag[node])
					{
						flag[i] = true;
					}
					break;
				}
			}
			continue;
		}
		for (auto& i : dp[node]) // 자식에게 전파
		{
			tt[i] += pivot;
			tt[node] -= pivot;
			pq.push(make_pair(grade[i], i));
		}
		if (!exp)
		{
			int _ = dp[node].back();
			if (flag[node])
			{
				flag[_] = true;
			}
			continue;
		}
		for (auto& i : dp[node])
		{
			tt[i] += (tt[node] ? 1 : 0);
			tt[node] = (0, tt[node] - 1);
			if (!tt[node])
			{
				if (flag[node])
				{
					flag[i] = true;
				}
				break;
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if (flag[i] && dp[i].empty())
		{
			cout << i;
			return 0;
		}
	}
	return 0;
}
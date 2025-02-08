#include <bits/stdc++.h>
#include <unordered_set>
#define MOD 998244353
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll>tl;
const char* yes = "Yes";
const char* no = "No";

struct cmp
{
	bool operator() (const tl& a, const tl& b)
	{
		if (get<0>(a) == get<0>(b))
		{
			return get<1>(a) < get<1>(b);
		}
		return get<0>(a) > get<0>(b);
	};
};

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0, cnt = 0, ver = 0;
	cin >> n >> m;
	vector<vector<pll>>g(n + 1);
	vector<int>low(n + 1, 0), num(n + 1, 0), id(n + 1, INT_MIN), s;
	vector<vector<int>>t(n + 1);
	vector<ll> dis(n + 1, LLONG_MAX), dp(n + 1, 0);
	vector<bool>in(n + 1, false), cycle(n + 1, false);
	for (int i = 0; i < m; ++i)
	{
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		g[a].push_back(make_pair(b, c));
		if (!c)
		{
			t[a].push_back(b);
		}
	}
	function<void(int)> scc = [&](int node)
		{
			low[node] = num[node] = ++cnt;
			s.push_back(node);
			in[node] = true;
			for (auto& i : t[node])
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
			if (num[node] == low[node])
			{
				vector<int>temp;
				while (1)
				{
					int a = s.back();
					s.pop_back();
					in[a] = false;
					id[a] = ver;
					temp.push_back(a);
					if (a == node)
					{
						break;
					}
				}
				if (temp.size() > 1)
				{
					for (auto& i : temp)
					{
						cycle[i] = true;
					}
				}
				ver++;
			}
		};
	for (int i = 1; i <= n; ++i)
	{
		if (!num[i] && !t[i].empty())
		{
			scc(i);
		}
	}
	priority_queue<tl, vector<tl>, cmp>pq; // 가중치, 우선순위, 정점
	pq.push(make_tuple(0, id[1], 1));
	dis[1] = 0, dp[1] = 1;
	while (!pq.empty())
	{
		auto [w, o, v] = pq.top();
		pq.pop();
		if (dis[v] < w)
		{
			continue;
		}
		for (auto& [nv, nw] : g[v])
		{
			ll cost = w + nw;
			if (dis[nv] > cost)
			{
				dis[nv] = cost;
				dp[nv] = dp[v];
				pq.push(make_tuple(cost, id[nv], nv));
			}
			else if (dis[nv] == cost)
			{
				dp[nv] = (dp[nv] + dp[v]) % MOD;
			}
		}
	}
	queue<int>q;
	for (int i = 1; i <= n; ++i)
	{
		if (cycle[i])
		{
			dp[i] = -1;
			q.push(i);
		}
	}
	while (!q.empty())
	{
		int a = q.front();
		q.pop();
		for (auto& [v, w] : g[a])
		{
			if (dis[v] == dis[a] + w && dp[v] != -1)
			{
				dp[v] = -1;
				q.push(v);
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << dp[i] << '\n';
	}
	return 0;
}
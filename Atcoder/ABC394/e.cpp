#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	vector<vector<char>>v(n, vector<char>(n));
	vector<vector<vector<ll>>>graph(n, vector<vector<ll>>(27));
	vector<vector<vector<ll>>>rev(n, vector<vector<ll>>(27));
	vector<vector<ll>>dist(n, vector<ll>(n, INT_MAX));
	queue<pii>q;
	for (ll i = 0; i < n; ++i)
	{
		dist[i][i] = 0;
		q.push(make_pair(i, i));
		string str;
		cin >> str;
		for (ll j = 0; j < n; ++j)
		{
			v[i][j] = str[j];
			if (v[i][j] != '-')
			{
				ll pivot = v[i][j] - 'a';
				graph[i][pivot].push_back(j);
				rev[j][pivot].push_back(i);
			}
		}
	}
	for (ll i = 0; i < n; ++i)
	{
		for (ll j = 0; j < 26; ++j)
		{
			for (auto& k : graph[i][j])
			{
				if (dist[i][k] == INT_MAX)
				{
					dist[i][k] = 1;
					q.push(make_pair(i, k));
				}
			}
		}
	}
	while (!q.empty())
	{
		auto [a, b] = q.front();
		q.pop();
		for (ll i = 0; i < 26; ++i)
		{
			for (auto& j : rev[a][i])
			{
				for (auto& k : graph[b][i])
				{
					if (dist[j][k] > dist[a][b] + 2)
					{
						dist[j][k] = dist[a][b] + 2;
						q.push(make_pair(j, k));
					}
				}
			}
		}
	}
	for (auto& i : dist)
	{
		for (auto& j : i)
		{
			if (j == INT_MAX)
			{
				cout << -1;
			}
			else
			{
				cout << j;
			}
			cout << ' ';
		}
		cout << '\n';
	}
	return 0;
}

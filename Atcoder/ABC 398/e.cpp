#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	set<pii>edge;
	vector<vector<int>>graph(n + 1);
	for (int i = 0; i < n - 1; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		edge.insert(make_pair(a, b));
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= n; ++i)
	{
		sort(graph[i].begin(), graph[i].end());
	}
	vector<int>color(n + 1, -1);
	color[1] = 0;
	queue<int>q;
	q.push(1);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto& i : graph[cur])
		{
			if (color[i] == -1)
			{
				color[i] = (color[cur] + 1) % 2;
				q.push(i);
			}
		}
	}
	set<pii>ok;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i + 1; j <= n; ++j)
		{
			if (color[i] != color[j])
			{
				if (binary_search(graph[i].begin(), graph[i].end(), j))
				{
					continue;
				}
				ok.insert(make_pair(i, j));
			}
		}
	}
	int turn = 0;
	if (ok.size() % 2)
	{
		cout << "First" << endl;
		turn = 1;
	}
	else
	{
		cout << "Second" << endl;
	}
	while (1)
	{
		if (turn)
		{
			auto it = ok.begin();
			auto [a, b] = *it;
			cout << a << ' ' << b << endl;
			ok.erase(it);
		}
		else
		{
			int a = 0, b = 0;
			cin >> a >> b;
			if (a == -1 && b == -1)
			{
				return 0;
			}
			int pa = min(a, b), pb = max(a, b);
			ok.erase(make_pair(pa, pb));
		}
		turn = (turn + 1) % 2;
	}
	return 0;
}

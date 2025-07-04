#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	vector<vector<int>>graph(n + 1);
	vector<int>degree(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[a].push_back(b);
		degree[b]++;
	}
	map<int, int>mm;
	while (k--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		if (a == 1)
		{
			if (degree[b])
			{
				cout << "Lier!";
				return 0;
			}
			if (++mm[b] == 1)
			{
				for (auto& i : graph[b])
				{
					degree[i]--;
				}
			}
		}
		else
		{
			if (mm.find(b) == mm.end())
			{
				cout << "Lier!";
				return 0;
			}
			if (--mm[b] == 0)
			{
				mm.erase(b);
				for (auto& i : graph[b])
				{
					degree[i]++;
				}
			}
		}
	}
	cout << "King-God-Emperor";
	return 0;
}
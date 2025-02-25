#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>v(n);
	map<int, int>parent;
	unordered_set<int>visited;
	for (auto& i : v)
	{
		cin >> i;
	}
	for (int i = 0; i < n; ++i)
	{
		if (i == 0)
		{
			parent[v[i]] = -1;
			visited.insert(v[i]);
		}
		else
		{
			if (visited.find(v[i]) != visited.end())
			{
				if (i + 1 < n && v[i + 1] == parent[v[i]])
				{
					visited.erase(v[i]);
				}
			}
			else
			{
				parent[v[i]] = v[i - 1];
				visited.insert(v[i]);
			}
		}
	}
	cout << parent.size() << '\n';
	for (auto& [a, b] : parent)
	{
		cout << b << ' ';
	}
	return 0;
}
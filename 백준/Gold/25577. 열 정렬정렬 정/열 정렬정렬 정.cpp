#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;

vector<int>graph[100001];
vector<bool>visited(100001, false);

void dfs(int start)
{
	for (auto& i : graph[start])
	{
		if (!visited[i])
		{
			visited[i] = true;
			dfs(i);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int result = 0;
	int n = 0;
	cin >> n;
	vector<pair<int,int>>v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i].first;
		v[i].second = i;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; ++i)
	{
		v[i].first = i;
	}
	sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b)
		{
			return a.second < b.second;
		});
	for (int i = 0; i < n; ++i)
	{
		graph[i].push_back(v[i].first);
	}
	for (int i = 0; i < n; ++i)
	{
		if (!visited[i])
		{
			result++;
			dfs(i);
		}
	}
	cout << n - result;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int>graph[3001];
vector<int>result;
int degree[3001] = { 0, };
int ary[3001] = { 0, };
int vertex = 0;

struct cmp
{
	bool operator()(const pair<int, int>& a, const pair<int, int>& b)
	{
		return a.second > b.second;
	}
};

void topo_sort()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>pq;
	for (int i = 1; i <= vertex; ++i)
	{
		if (!degree[i])
		{
			pq.push(make_pair(i, ary[i]));
		}
	}
	while (!pq.empty())
	{
		pair<int, int> current = pq.top();
		pq.pop();
		result.push_back(current.second);
		for (auto& i : graph[current.first])
		{
			if (!(--degree[i]))
			{
				pq.push(make_pair(i, ary[i]));
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> vertex;
	for (int i = 1; i <= vertex; ++i)
	{
		cin >> ary[i];
	}
	for (int i = 1; i <= vertex; ++i)
	{
		for (int j = i + 1; j <= vertex; ++j)
		{
			if (gcd(ary[i], ary[j]) != 1)
			{
				graph[i].push_back(j);
				degree[j]++;
			}
		}
	}
	topo_sort();
	for (auto& i : result)
	{
		cout << i << " ";
	}
	return 0;
}
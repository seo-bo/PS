#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string mapp[51];
vector<int>graph[51];
int degree[51];
int vertex = 0, edge = 0;

void topo_sort()
{
	queue<int>q;
	for (int i = 1; i <= vertex; ++i)
	{
		if (!degree[i])
		{
			q.push(i);
		}
	}
	int count = 0;
	while (!q.empty())
	{
		int current = q.front();
		q.pop();
		for (auto& i : graph[current])
		{
			count++;
			if (!(--degree[i]))
			{
				q.push(i);
			}
		}
	}
	if (count == edge)
	{
		cout << "YES";
		exit(0);
	}
	else
	{
		cout << "NO";
		exit(0);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> vertex;
	for (int i = 0; i < vertex; ++i)
	{
		cin >> mapp[i];
	}
	for (int i = 0; i < vertex; ++i)
	{
		for (int j = 0; j < vertex; ++j)
		{
			if (mapp[i][j] == 'Y' && mapp[j][i] == 'Y')
			{
				mapp[i][j] = 'N';
				mapp[j][i] = 'N';
			}
			if (mapp[i][j] == 'Y')
			{
				edge++;
				graph[i + 1].push_back(j + 1);
				degree[j + 1]++;
			}
		}
	}
	topo_sort();
	return 0;
}
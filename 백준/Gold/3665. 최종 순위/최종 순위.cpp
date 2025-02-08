#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int>result;
int board[501][501] = { 0, };
int ary[501] = { 0, };
int idx[501] = { 0, };
int degree[501] = { 0, };
int vertex = 0, edge = 0;

int topo_sort(vector<int> graph[])
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
		count++;
		result.push_back(current);
		for (auto& i : graph[current])
		{
			if (!(--degree[i]))
			{
				q.push(i);
			}
		}
	}
	if (vertex != count)
	{
		return 0;
	}
	return 1;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int test = 0;
	cin >> test;
	while (test--)
	{
		memset(degree, 0, sizeof(degree));
		memset(board, 0, sizeof(board));
		memset(idx, 0, sizeof(idx));
		memset(ary, 0, sizeof(ary));
		vector<int>().swap(result);
		cin >> vertex;
		for (int i = 1; i <= vertex; ++i)
		{
			for (int j = i + 1; j <= vertex; ++j)
			{
				board[i][j] = 1;
			}
		}
		for (int i = 1; i <= vertex; ++i)
		{
			cin >> idx[i];
			ary[idx[i]] = i;
		}
		cin >> edge;
		for (int i = 0; i < edge; ++i)
		{
			int start = 0, fin = 0;
			cin >> start >> fin;
			board[ary[start]][ary[fin]] ^= 1;
			board[ary[fin]][ary[start]] ^= 1;
		}
		vector<int>graph[501];
		for (int i = 1; i <= vertex; ++i)
		{
			for (int j = 1; j <= vertex; ++j)
			{
				if (board[i][j])
				{
					graph[i].push_back(j);
					degree[j]++;
				}
			}
		}
		if (!topo_sort(graph))
		{
			cout << "IMPOSSIBLE" << "\n";
			continue;
		}
		for (auto& i : result)
		{
			cout << idx[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}
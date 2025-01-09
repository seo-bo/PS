#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100001];
vector<int> child[100001];
int dp[100001] = { 0, };

void makeTree(int current, int parent)
{
	for (auto& i : graph[current])
	{
		if (i != parent)
		{
			child[current].push_back(i);
			makeTree(i, current);
		}
	}
}

void counter(int current)
{
	dp[current] = 1;
	for (auto& i : child[current])
	{
		counter(i);
		dp[current] += dp[i];
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0, root = 0, query = 0;
	cin >> num >> root >> query;
	for (int i = 0; i < num - 1; ++i)
	{
		int p = 0, c = 0;
		cin >> p >> c;
		graph[p].push_back(c);
		graph[c].push_back(p);
	}
	makeTree(root, -1);
	counter(root);
	for (int i = 0; i < query; ++i)
	{
		int temp = 0;
		cin >> temp;
		cout << dp[temp] << "\n";
	}
	return 0;
}
#include <bits/stdc++.h>
typedef long long ll;
typedef long double lb;
using namespace std;

struct MST
{
	int start;
	int end;
	int weight;
	bool operator>(const MST& a) const
	{
		return weight > a.weight;
	}
};

priority_queue<MST, vector<MST>, greater<MST>>pq;
int parent[51] = { 0, };

int Find(int x)
{
	if (parent[x] == x)
	{
		return x;
	}
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	if (x != y)
	{
		parent[y] = x;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	iota(parent, parent + 1 + n, 0);
	ll result = 0, cnt = 0;
	for (int i = 1; i <= n; ++i)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < n; ++j)
		{
			if ('a' <= temp[j] && temp[j] <= 'z')
			{
				int value = temp[j] - 'a' + 1;
				result += value;
				pq.push({ i,j + 1,value });
			}
			else if ('A' <= temp[j] && temp[j] <= 'Z')
			{
				int value = temp[j] - 'A' + 27;
				result += value;
				pq.push({ i,j + 1,value });
			}
		}
	}
	while (!pq.empty() && cnt < n - 1)
	{
		MST edge = pq.top();
		pq.pop();
		if (Find(edge.start) != Find(edge.end))
		{
			Union(edge.start, edge.end);
			result -= edge.weight;
			cnt++;
		}
	}
	if (cnt != n - 1)
	{
		cout << -1;
	}
	else
	{
		cout << result;
	}
	return 0;
}

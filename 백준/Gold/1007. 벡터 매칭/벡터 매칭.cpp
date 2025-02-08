#include <bits/stdc++.h>
#include <unordered_map>
#define INF 2000000000
using namespace std;
typedef long long ll;
typedef long double lb;

vector<pair<lb, lb>>line;
int visited[30] = { 0, };
int num = 0;
lb result = 0;

void dfs(int start, int depth)
{
	if (depth == num / 2)
	{
		pair<lb, lb> temp = { 0,0 };
		for (int i = 0; i < num; ++i)
		{
			if (!visited[i])
			{
				temp.first += line[i].first;
				temp.second += line[i].second;
			}
			else
			{
				temp.first -= line[i].first;
				temp.second -= line[i].second;
			}
		}
		result = min(result, (lb)sqrt((lb)temp.first * (lb)temp.first + (lb)temp.second * (lb)temp.second));
		return;
	}
	for (int i = start; i < num; ++i)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			dfs(i + 1, depth + 1);
			visited[i] = 0;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int test = 0;
	cin >> test;
	while (test--)
	{
		result = 1e20;
		cin >> num;
		line.resize(num, { 0,0 });
		for (int i = 0; i < num; ++i)
		{
			cin >> line[i].first >> line[i].second;
		}
		dfs(0, 0);
		cout << fixed << setprecision(8) << result << "\n";
		memset(visited, 0, sizeof(visited));
		vector<pair<lb, lb>>().swap(line);
	}
	return 0;
}
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef long double lb;

vector<int>v(11);
ll result = 0;

void dfs(int depth, int score, int prev1 = -1, int prev2 = -1)
{
	if (depth > 10)
	{
		if (score >= 5)
		{
			result++;
		}
		return;
	}
	for (int i = 1; i <= 5; ++i)
	{
		if (i != prev1 || i != prev2)
		{
			int news = score;
			if (v[depth] == i)
			{
				news++;
			}
			dfs(depth + 1, news, i, prev1);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 1; i <= 10; ++i)
	{
		cin >> v[i];
	}
	dfs(1, 0);
	cout << result;
	return 0;
}
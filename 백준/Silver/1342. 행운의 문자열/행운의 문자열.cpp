#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef long double lb;

int visited[30] = { 0, };
string str = "";
ll result = 0;

void dfs(int depth = 0, char prev = '?')
{
	if (depth == str.length())
	{
		result++;
		return;
	}
	for (int i = 0; i < 26; ++i)
	{
		if (visited[i] && i + 'a' != prev)
		{
			visited[i]--;
			dfs(depth + 1, 'a' + i);
			visited[i]++;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> str;
	for (auto& i : str)
	{
		visited[i - 'a']++;
	}
	dfs();
	cout << result;
	return 0;
}
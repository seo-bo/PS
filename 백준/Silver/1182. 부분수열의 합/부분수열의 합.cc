#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef long double lb;

vector<ll>v(21);
int N = 0, S = 0;
ll result = 0;

void dfs(int depth, ll sum = 0)
{
	if (sum == S)
	{
		result++;
	}
	for (int i = depth; i <= N; ++i)
	{
		dfs(i + 1, sum + v[i]);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> S;
	for (int i = 1; i <= N; ++i)
	{
		cin >> v[i];
	}
	dfs(1);
	if (!S)
	{
		cout << result - 1;
	}
	else
	{
		cout << result;
	}
	return 0;
}
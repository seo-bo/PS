#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lb;

bool prime[10001];
bool visited[10];
unordered_map<int, int>m;
vector<int>result;
vector<int>v;

int N = 0, M = 0;

void get_prime()
{
	fill(prime + 2, prime + 10001, true);
	for (int i = 2; i * i <= 10000; ++i)
	{
		if (prime[i])
		{
			for (int j = i * i; j <= 10000; j += i)
			{
				prime[j] = false;
			}
		}
	}
}

void dfs(int depth = 0, int sum = 0)
{
	if (depth == M)
	{
		if (prime[sum])
		{
			if (m.find(sum) == m.end())
			{
				m.insert(make_pair(sum, 1));
				result.push_back(sum);
				return;
			}
		}
	}
	for (int i = 0; i < N; ++i)
	{
		if (!visited[i])
		{
			visited[i] = true;
			dfs(depth + 1, sum + v[i]);
			visited[i] = false;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	get_prime();
	cin >> N >> M;
	v.resize(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
	}
	dfs();
	if (result.empty())
	{
		cout << -1;
		return 0;
	}
	sort(result.begin(), result.end());
	for (auto& i : result)
	{
		cout << i << " ";
	}
	return 0;
}
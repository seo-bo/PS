#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, ans = 0;
	cin >> n;
	vector<vector<int>>graph(n);
	for (int i = 0; i < n; ++i)
	{
		int temp = 0;
		cin >> temp;
		if (temp != -1)
		{
			graph[temp].push_back(i);
		}
	}
	function<int(int)> dfs = [&](int node) -> int
		{
			if (graph[node].empty())
			{
				return 0;
			}
			vector<int>temp;
			for (auto& i : graph[node])
			{
				temp.push_back(dfs(i));
			}
			sort(temp.begin(), temp.end(), greater<int>());
			int sum = 0;
			for (int i = 0; i < temp.size(); ++i)
			{
				sum = max(sum, temp[i] + i + 1);
			}
			return sum;
		};
	cout << dfs(0);
	return 0;
}
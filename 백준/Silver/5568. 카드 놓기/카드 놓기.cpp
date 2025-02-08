#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, k = 0;
	cin >> n >> k;
	vector<string>v;
	vector<bool>visited(n + 1, false);
	unordered_map<string, int>m;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		v.push_back(str);
	}
	function<void(int, string)> dfs = [&](int depth, string s) -> void
		{
			if (depth == k)
			{
				m[s] = 1;
				return;
			}
			for (int i = 0; i < n; ++i)
			{
				if (!visited[i])
				{
					visited[i] = true;
					dfs(depth + 1, s + v[i]);
					visited[i] = false;
				}
			}
		};
	dfs(0, "");
	cout << m.size();
	return 0;
}
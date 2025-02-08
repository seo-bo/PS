#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void) // 1 5 9 13
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int>v = { 1,5,10,50 };
	unordered_set<int>visited;
	int n = 0, ans = 0;
	cin >> n;
	function<void(int, int, int)> dfs = [&](int depth, int sum, int start) ->void
		{
			if (depth == n)
			{
				visited.insert(sum);
				return;
			}
			for (int i = start; i < 4; ++i)
			{
				dfs(depth + 1, sum + v[i], i);
			}
		};
	dfs(0, 0, 0);
	cout << visited.size();
	return 0;
}
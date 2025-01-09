#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int k = 0;
	cin >> k;
	int n = ((1 << k) - 1);
	vector<int>v(n);
	vector<int>result[10];
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	function<void(int, int, int)> dfs = [&](int start, int end, int depth) -> void
		{
			if (start == end)
			{
				return;
			}
			int mid = (start + end) / 2;
			result[depth].push_back(v[mid]);
			dfs(start, mid, depth + 1);
			dfs(mid + 1, end, depth + 1);
		};
	dfs(0, n, 0);
	for (auto& i : result)
	{
		if (i.empty())
		{
			break;
		}
		for (auto& j : i)
		{
			cout << j << " ";
		}
		cout << "\n";
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void) // 26159번님 감사합니다...
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, q = 0;
	cin >> n >> q;
	vector<int> tree((n + 4) * 4, 0);
	vector<vector<int>> graph(n);
	vector<int>S = { 0, };
	vector<int>level(n, 1);
	vector<int>siz(n, 1);
	function<void(int, int, int, int, int)> update = [&](int start, int end, int node, int idx, int value)
		{
			if (start == end)
			{
				tree[node] = value;
				return;
			}
			int mid = (start + end) / 2;
			if (idx <= mid)
			{
				update(start, mid, node * 2, idx, value);
			}
			else
			{
				update(mid + 1, end, node * 2 + 1, idx, value);
			}
			tree[node] = tree[node * 2] + tree[node * 2 + 1];
		};
	function<int(int, int, int, int, int)> query = [&](int start, int end, int node, int left, int right) -> int
		{
			if (left > end || right < start)
			{
				return 0;
			}
			if (left <= start && end <= right)
			{
				return tree[node];
			}
			int mid = (start + end) / 2;
			return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
		};
	function<void(int)> dfs = [&](int node)
		{
			siz[node] = 1;
			for (auto& i : graph[node])
			{
				dfs(i);
				siz[node] += siz[i];
			}
		};
	int head = 1, lev = 0;
	auto c = [&](int s)
		{
			while (lev > s)
			{
				int t = S.back();
				S.pop_back();
				level[S.back()] += level[t];
				lev--;
			}
		};
	for (int i = 0; i < n; ++i)
	{
		int j = 0;
		char type;
		cin >> j >> type;
		c(j);
		if (type == 'h')
		{
			graph[S.back()].push_back(head);
			S.push_back(head++);
		}
		else
		{
			level[S.back()]++;
		}
		lev = j;
	}
	c(0);
	dfs(0);
	while (q--)
	{
		char type;
		cin >> type;
		if (type == 't')
		{
			int num;
			cin >> num;
			if (query(0, n - 1, 1, num, num) == 0)
			{
				update(0, n - 1, 1, num, level[num] - query(0, n - 1, 1, num + 1, num + siz[num] - 1) - 1);
			}
			else
			{
				update(0, n - 1, 1, num, 0);
			}
		}
		else
		{
			cout << level[0] - query(0, n - 1, 1, 0, n - 1) - 1 << '\n';
		}
	}
	return 0;
}
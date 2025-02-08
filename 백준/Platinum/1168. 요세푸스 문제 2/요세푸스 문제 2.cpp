#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, k = 0;
	cin >> n >> k;
	vector<int>tree((n + 2) * 4, 0);
	function<void(int, int, int)> init = [&](int start, int end, int node)
		{
			if (start == end)
			{
				tree[node] = 1;
				return;
			}
			int mid = (start + end) / 2;
			init(start, mid, node * 2);
			init(mid + 1, end, node * 2 + 1);
			tree[node] = tree[node * 2] + tree[node * 2 + 1];
		};
	function<void(int, int, int, int, int)> update = [&](int start, int end, int node, int idx, int value)
		{
			if (idx < start || idx > end)
			{
				return;
			}
			if (start == end)
			{
				tree[node] += value;
				return;
			}
			int mid = (start + end) / 2;
			update(start, mid, node * 2, idx, value);
			update(mid + 1, end, node * 2 + 1, idx, value);
			tree[node] = tree[node * 2] + tree[node * 2 + 1];
		};
	function<int(int, int, int, int)> query = [&](int start, int end, int node, int k) -> int
		{
			if (start == end)
			{
				return start;
			}
			int mid = (start + end) / 2;
			if (tree[node * 2] >= k)
			{
				return query(start, mid, node * 2, k);
			}
			else
			{
				return query(mid + 1, end, node * 2 + 1, k - tree[node * 2]);
			}
		};
	init(1, n, 1);
	cout << "<";
	int p = 0;
	for (int i = 0; i < n; ++i)
	{
		int len = n - i;
		p = (p + k - 1) % len;
		int a = query(1, n, 1, p + 1);
		cout << a;
		if (i < n - 1)
		{
			cout << ", ";
		}
		else
		{
			cout << ">";
		}
		update(1, n, 1, a, -1);
	}
	return 0;
}
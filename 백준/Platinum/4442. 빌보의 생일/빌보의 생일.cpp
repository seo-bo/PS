#include <bits/stdc++.h>
using namespace std;
typedef long double lb;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int>tree;
	while (1)
	{
		int N = 0;
		cin >> N;
		if (!N)
		{
			break;
		}
		vector<int>((N + 1) * 4, 0).swap(tree);
		function<void(int, int, int, int)> update = [&](int start, int end, int node, int idx) -> void
			{
				if (start > idx || idx > end)
				{
					return;
				}
				if (idx <= start && end <= idx)
				{
					tree[node] = 1;
					return;
				}
				int mid = (start + end) / 2;
				update(start, mid, node * 2, idx);
				update(mid + 1, end, node * 2 + 1, idx);
				tree[node] = tree[node * 2] + tree[node * 2 + 1];
			};
		function<int(int, int, int, int, int)> query = [&](int start, int end, int node, int left, int right) ->int
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
		unordered_map<string, int>m;
		for (int i = 1; i <= N; ++i)
		{
			string temp;
			cin >> temp;
			m[temp] = i;
		}
		ll ans = 0;
		for (int i = 0; i < N; ++i)
		{
			string temp;
			cin >> temp;
			ans += query(1, N, 1, m[temp] + 1, N);
			update(1, N, 1, m[temp]);
		}
		cout << ans << "\n";
	}
	return 0;
}
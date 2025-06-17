#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	vector<ll>v(n + 1), prefix(n + 3);
	vector<pll>tree(4 * (n + 2));
	auto cal = [&](pll a, pll b)
		{
			return (a.first > b.first) ? a : (a.first < b.first) ? b : (a.second < b.second) ? a : b;
		};
	function<void(int, int, int, int, ll)> update = [&](int start, int end, int node, int idx, ll delta)
		{
			if (idx < start || idx > end)
			{
				return;
			}
			if (start == end)
			{
				tree[node] = { delta,idx };
				return;
			}
			int mid = (start + end) >> 1;
			update(start, mid, node * 2, idx, delta);
			update(mid + 1, end, node * 2 + 1, idx, delta);
			tree[node] = cal(tree[node * 2], tree[node * 2 + 1]);
		};
	pll base = { (-1LL << 40), (1LL << 40) };
	function<pll(int, int, int, int, int)> query = [&](int start, int end, int node, int left, int right)
		{
			if (left > end || right < start)
			{
				return base;
			}
			if (left <= start && end <= right)
			{
				return tree[node];
			}
			int mid = (start + end) >> 1;
			return cal(query(start, mid, node * 2, left, right), query(mid + 1, end, node * 2 + 1, left, right));
		};
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		prefix[i] = prefix[i - 1] + v[i];
		update(1, n, 1, i, prefix[i]);
	}
	if (n == 1)
	{
		cout << v[1] << '\n';
		cout << 1 << ' ' << 1 << '\n';
		return 0;
	}
	ll ans = -prefix[n], l = 2, r = 1; // 전체 -1 곱하는 방법, 크로스 하면 손해아닌가?
	for (int i = 1; i <= n; ++i)
	{
		pll pivot = query(1, n, 1, i, min(n, i + k));
		ll left = i, right = pivot.second;
		ll sum = -prefix[left - 1] + (pivot.first - prefix[left - 1]) - (prefix[n] - prefix[right]);
		if (sum > ans)
		{
			ans = sum;
			l = left, r = right;
		}
		else if (sum == ans)
		{
			if (l > left)
			{
				l = left, r = right;
			}
			else if (l == left && r > right)
			{
				r = right;
			}
		}
	}
	cout << ans << '\n';
	cout << l << ' ' << r << '\n';
	return 0;
}
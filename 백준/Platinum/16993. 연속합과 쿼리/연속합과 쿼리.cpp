#include <bits/stdc++.h>
#define INF -(1<<27)
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int, int>tl;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	int N = n + 1;
	vector<int>v(N);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	vector<int>sum(4 * N), prefix(4 * N), suffix(4 * N), ans(4 * N);
	auto merge = [&](int node)
		{
			int left = node * 2, right = node * 2 + 1;
			sum[node] = sum[left] + sum[right];
			prefix[node] = max(prefix[left], sum[left] + prefix[right]);
			suffix[node] = max(suffix[right], sum[right] + suffix[left]);
			ans[node] = max({ ans[left], ans[right], suffix[left] + prefix[right] });
		};
	function<void(int, int, int)> init = [&](int start, int end, int node)
		{
			if (start == end)
			{
				sum[node] = prefix[node] = suffix[node] = ans[node] = v[start];
				return;
			}
			int mid = (start + end) / 2;
			init(start, mid, node * 2);
			init(mid + 1, end, node * 2 + 1);
			merge(node);
		};
	function<tl(int, int, int, int, int)> query = [&](int start, int end, int node, int left, int right)->tl
		{
			if (right < start || left > end)
			{
				return make_tuple(0, INF, INF, INF);
			}
			if (left <= start && end <= right)
			{
				return make_tuple(sum[node], prefix[node], suffix[node], ans[node]);
			}
			int mid = (start + end) / 2;
			auto [ls, lp, lsf, lm] = query(start, mid, node * 2, left, right);
			auto [rs, rp, rsf, rm] = query(mid + 1, end, node * 2 + 1, left, right);
			return make_tuple(ls + rs, max(lp, ls + rp), max(rsf, rs + lsf), max({ lm, rm, lsf + rp }));
		};
	init(1, n, 1);
	int m = 0;
	cin >> m;
	while (m--)
	{
		int l = 0, r = 0;
		cin >> l >> r;
		cout << get<3>(query(1, n, 1, l, r)) << '\n';
	}
	return 0;
}
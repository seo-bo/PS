#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node
{
	ll sum, prefix, suffix, maxi;
};

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	vector<Node>tree(4 * (n + 2));
	auto comb = [&](Node left, Node right)
		{
			Node res;
			res.sum = left.sum + right.sum;
			res.prefix = max(left.prefix, left.sum + right.prefix);
			res.suffix = max(right.suffix, right.sum + left.suffix);
			res.maxi = max({ left.maxi,right.maxi,left.suffix + right.prefix });
			return res;
		};
	function<void(int, int, int)> init = [&](int start, int end, int node)
		{
			if (start == end)
			{
				tree[node] = { v[start],v[start],v[start] ,v[start] };
				return;
			}
			int mid = (start + end) >> 1;
			init(start, mid, node * 2);
			init(mid + 1, end, node * 2 + 1);
			tree[node] = comb(tree[node * 2], tree[node * 2 + 1]);
		};
	function<Node(int, int, int, int, int)> query = [&](int start, int end, int node, int left, int right)
		{
			if (start > right || end < left)
			{
				Node temp = { 0, LLONG_MIN / 2,LLONG_MIN / 2 ,LLONG_MIN / 2 };
				return temp;
			}
			if (left <= start && end <= right)
			{
				return tree[node];
			}
			int mid = (start + end) >> 1;
			return comb(query(start, mid, node * 2, left, right), query(mid + 1, end, node * 2 + 1, left, right));
		};
	init(1, n, 1);
	int q = 0;
	cin >> q;
	while (q--)
	{
		int a = 0, b = 0, c = 0, d = 0;
		cin >> a >> b >> c >> d;
		assert((a <= c) && (b <= d) && (a <= b) && (c <= d));
		if (c <= b) // a c b d
		{
			cout << max({ query(1, n, 1, c, b).maxi, query(1, n, 1, a, c - 1).suffix + query(1, n, 1, c, d).prefix, query(1, n, 1, a, b).suffix + query(1, n, 1, b + 1, d).prefix }) << '\n';
		}
		else // a b c d
		{
			cout << query(1, n, 1, a, b).suffix + query(1, n, 1, c, d).prefix + query(1, n, 1, b + 1, c - 1).sum << '\n';
		}
	}
	return 0;
}
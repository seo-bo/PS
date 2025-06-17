#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node
{
	ll prefix, suffix, maxi;
	char L, R;
};

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, q = 0;
	cin >> n >> q;
	vector<char>v(n + 1, 'L');
	vector<Node>tree(4 * (n + 3));
	auto comb = [&](Node left, Node right, int llen, int rlen)
		{
			// 합쳐 줄려면 prefix나 suffix가 길이랑 같아야하는데 굳이 sum으로 길이를 잴 필요도..?
			// 일단 "할 수도 있다"가 아니라 연속된 문자가 같으면 "그냥 못합치는거" 아닌가?
			Node res = { 1,1,1,left.L,right.R };
			ll co1 = (left.R == right.L) ? INT_MIN : 0;
			ll co2 = (left.prefix != llen) ? INT_MIN : 0;
			ll co3 = (right.suffix != rlen) ? INT_MIN : 0;
			res.prefix = max(left.prefix, left.prefix + right.prefix + co1 + co2);
			res.suffix = max(right.suffix, left.suffix + right.prefix + co1 + co3);
			res.maxi = max({ left.maxi, right.maxi, res.prefix, res.suffix, left.suffix + right.prefix + co1 });
			return res;
		};
	function<void(int, int, int, int, char)> update = [&](int start, int end, int node, int idx, char delta)
		{
			if (idx > end || idx < start)
			{
				return;
			}
			if (start == end)
			{
				tree[node] = { 1,1,1,delta,delta };
				return;
			}
			int mid = (start + end) >> 1;
			if (idx <= mid)
			{
				update(start, mid, node * 2, idx, delta);
			}
			else
			{
				update(mid + 1, end, node * 2 + 1, idx, delta);
			}
			tree[node] = comb(tree[node * 2], tree[node * 2 + 1], mid - start + 1, end - mid);
		};
	for (int i = 1; i <= n; ++i)
	{
		update(1, n, 1, i, v[i]);
	}
	while (q--)
	{
		int a = 0;
		cin >> a;
		v[a] = (v[a] == 'L') ? 'R' : 'L';
		update(1, n, 1, a, v[a]);
		cout << tree[1].maxi << '\n';
	}
	return 0;
}
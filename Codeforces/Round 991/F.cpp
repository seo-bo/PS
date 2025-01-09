#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0, q = 0;
		cin >> n >> q;
		vector<ll>v(n + 1, 0);
		for (int i = 1; i <= n; ++i)
		{
			cin >> v[i];
		}
		vector<ll>diff;
		if (n >= 2)
		{
			for (int i = 2; i <= n; ++i)
			{
				diff.push_back(abs(v[i] - v[i - 1]));
			}
		}
		int len = diff.size();
		vector<ll>tree((len + 1) * 4, 0);
		function<void(int, int, int)> init = [&](int start, int end, int node)
			{
				if (start == end)
				{
					tree[node] = diff[start - 1];
					return;
				}
				int mid = (start + end) / 2;
				init(start, mid, node * 2);
				init(mid + 1, end, node * 2 + 1);
				tree[node] = gcd(tree[node * 2], tree[node * 2 + 1]);
			};
		function<ll(int, int, int, int, int)> query = [&](int start, int end, int node, int left, int right)
			{
				if (right < start || end < left)
				{
					return 0LL;
				}
				if (left <= start && end <= right)
				{
					return tree[node];
				}
				int mid = (start + end) / 2;
				ll a = query(start, mid, node * 2, left, right);
				ll b = query(mid + 1, end, node * 2 + 1, left, right);
				if (!a)
				{
					return b;
				}
				if (!b)
				{
					return a;
				}
				return gcd(a, b);
			};
		if (len > 0)
		{
			init(1, len, 1);
		}
		vector<ll>ans;
		while (q--)
		{
			int l = 0, r = 0;
			cin >> l >> r;
			if (l == r)
			{
				ans.push_back(0);
				continue;
			}
			ans.push_back(query(1, len, 1, l, r - 1));
		}
		for (auto& i : ans)
		{
			cout << i << ' ';
		}
		cout << '\n';
	}
}

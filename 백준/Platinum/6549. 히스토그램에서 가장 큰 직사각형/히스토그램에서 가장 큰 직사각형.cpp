#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	while (1)
	{
		int n = 0;
		cin >> n;
		if (!n)
		{
			break;
		}
		ll ans = 0;
		vector<ll>v(n);
		for (auto& i : v)
		{
			cin >> i;
			ans = max(ans, i);
		}
		function<ll(int, int)> dfs = [&](int left, int right) ->ll
			{
				if (left == right)
				{
					return v[left];
				}
				int mid = (left + right) / 2, l = mid, r = mid + 1;
				ll h = min(v[l], v[r]), mm = h * 2;
				mm = max({ dfs(left,mid),dfs(mid + 1,right),mm });
				while (l > left || r < right)
				{
					if (r < right && (l == left || v[r + 1] >= v[l - 1]))
					{
						h = min(h, v[++r]);
					}
					else
					{
						h = min(h, v[--l]);
					}
					mm = max(mm, h * (r - l + 1));
				}
				return mm;
			};
		cout << dfs(0, n - 1) << '\n';
	}
	return 0;
}
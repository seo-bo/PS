#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	if (n < 3)
	{
		cout << 0;
		return 0;
	}
	if (n < 5)
	{
		cout << 1;
		return 0;
	}
	map<ll, ll>memo;
	function<ll(ll)> dfs = [&](ll pivot)
		{
			if (pivot <= 2)
			{
				return 0LL;
			}
			if (pivot <= 4)
			{
				return 1LL;
			}
			if (memo.find(pivot) != memo.end())
			{
				return memo[pivot];
			}
			ll div = (pivot - 2) / 3, cnt = 2 + dfs(div);
			ll p = pivot - 2 - div;
			ll ans = 0;
			ll left = div, right = p - left;
			while (left <= right)
			{
				ans = max(ans, cnt + dfs(left) + dfs(right));
				left++;
				right--;
			}
			return memo[pivot] = ans;
		};
	cout << dfs(n);
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, ans = 0;
	cin >> n;
	vector<int>v(n, -1);
	auto check = [&](int depth)
		{
			for (int i = 0; i < depth; ++i)
			{
				if (v[i] == v[depth] || abs(v[depth] - v[i]) == depth - i) // 열번호 / 행번호 차이
				{
					return false;
				}
			}
			return true;
		};

	function<void(int)> dfs = [&](int depth)
		{
			if (depth == n)
			{
				ans++;
				return;
			}
			for (int i = 0; i < n; ++i)
			{
				v[depth] = i; // 어쩌피 뒤집어 쓰니까?
				if (check(depth))
				{
					dfs(depth + 1);
				}
			}
		};
	dfs(0);
	cout << ans;
	return 0;
}
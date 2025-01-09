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
	cin.tie(0)->ios::sync_with_stdio(0);
	string n;
	cin >> n;
	auto check = [&](string pivot)
		{
			ll num = stoll(pivot);
			for (auto& i : n)
			{
				ll a = i - '0';
				if (!a)
				{
					continue;
				}
				if (num % a)
				{
					return;
				}
			}
			cout << pivot;
			exit(0);
		};
	function<void(int, int, string)> dfs = [&](int depth, int limit, string temp)
		{
			if (depth == limit)
			{
				check(n + temp);
				return;
			}
			for (int i = 0; i <= 9; ++i)
			{
				dfs(depth + 1, limit, temp + to_string(i));
			}
		};
	for (int i = 0;; ++i)
	{
		dfs(0, i, "");
	}
	return 0;
}
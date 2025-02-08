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
	int n = 0, l = 0;
	cin >> n >> l;
	vector<string>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	auto check = [&](int idx, char A, int mask) -> tuple<bool, int>
		{
			int temp = mask;
			for (int i = 0; i < n; ++i)
			{
				if (v[i][idx] != A)
				{
					if ((1 << i) & temp)
					{
						return make_tuple(false, mask);
					}
					else
					{
						temp |= 1 << i;
					}
				}
			}
			return make_tuple(true, temp);
		};
	function<void(string, int, int)> dfs = [&](string str, int mask, int depth)
		{
			if (depth == l)
			{
				cout << str;
				exit(0);
			}
			for (char i = 'A'; i <= 'Z'; ++i)
			{
				auto [a, b] = check(depth, i, mask);
				if (a)
				{
					dfs(str + i, b, depth + 1);
				}
			}
		};
	dfs("", 0, 0);
	cout << "CALL FRIEND" << '\n';
	return 0;
}
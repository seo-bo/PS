#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int l = 0, c = 0, ac = 0, bc = 0;
	unordered_set<char>s = { 'a','e','i','o','u' };
	cin >> l >> c;
	vector<char>v(c);
	for (auto& i : v)
	{
		cin >> i;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < c; ++i)
	{
		if (s.find(v[i]) != s.end())
		{
			ac |= (1 << i);
		}
		else
		{
			bc |= (1 << i);
		}
	}
	function<void(string, int, int)> dfs = [&](string str, int start, int mask)
		{
			if (str.length() == l)
			{
				if (__builtin_popcount(mask & ac) >= 1 && __builtin_popcount(mask & bc) >= 2)
				{
					cout << str << '\n';
				}
				return;
			}
			for (int i = start; i < c; ++i)
			{
				if (!(mask & (1 << i)))
				{
					dfs(str + v[i], i + 1, mask | (1 << i));
				}
			}
		};
	dfs("", 0, 0);
	return 0;
}
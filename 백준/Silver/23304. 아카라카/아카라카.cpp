#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	auto sv = [&](int l, int r)
		{
			while (l <= r)
			{
				if (str[l++] != str[r--])
				{
					return false;
				}
			}
			return true;
		};
	function<void(int, int)> dfs = [&](int left, int right)
		{
			if (left == right)
			{
				return;
			}
			if (!sv(left, right))
			{
				cout << "IPSELENTI";
				exit(0);
			}
			int siz = right - left + 1;
			dfs(left, left + siz / 2 - 1);
			dfs(right - siz / 2 + 1, right);
		};
	dfs(0, str.size() - 1);
	cout << "AKARAKA";
	return 0;
}
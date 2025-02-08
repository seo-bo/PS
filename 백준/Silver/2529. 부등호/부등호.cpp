#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<char>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	string mini, maxi;
	ll mi = LLONG_MAX, ma = LLONG_MIN;
	function<void(int, int, string)> dfs = [&](int depth, int mask, string temp) ->void
		{
			if (depth > n)
			{
				ll num = stoll(temp);
				if (num < mi)
				{
					mini = temp;
					mi = num;
				}
				if (num > ma)
				{
					maxi = temp;
					ma = num;
				}
				return;
			}
			for (int i = 0; i <= 9; ++i)
			{
				if (!(mask & (1 << i)))
				{
					bool check = false;
					if (depth == 0 || (v[depth] == '>' && temp.back() > (i + '0')) || (v[depth] == '<' && temp.back() < (i + '0')))
					{
						check = true;
					}
					if (check)
					{
						mask |= (1 << i);
						temp.push_back(i + '0');
						dfs(depth + 1, mask, temp);
						temp.pop_back();
						mask &= ~(1 << i);
					}
				}
			}
		};
	dfs(0, 0, "");
	cout << maxi << '\n';
	cout << mini;
	return 0;
}
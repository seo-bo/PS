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
	string a = "antic";
	int mask = 0;
	for (auto& i : a)
	{
		mask |= (1 << (i - 'a'));
	}
	int n = 0, k = 0;
	cin >> n >> k;
	if (k < 5)
	{
		cout << 0;
		return 0;
	}
	vector<int>v(n, 0);
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		for (auto& _ : str)
		{
			v[i] |= (1 << (_ - 'a'));
		}
	}
	int ans = 0;
	function<void(int, int, int)> dfs = [&](int depth, int ma, int start)
		{
			if (depth == k - 5)
			{
				int c = 0;
				for (auto& i : v)
				{
					if ((ma & i) == i)
					{
						c++;
					}
				}
				ans = max(ans, c);
				return;
			}
			for (int i = start; i < 26; ++i) // ? 무조건 26개 전부다 전탐색해야하나?
			{
				if (!(ma & (1 << i)))
				{
					dfs(depth + 1, ma | (1 << i), i + 1);
				}
			}
		};
	dfs(0, mask, 0);
	cout << ans;
	return 0;
}
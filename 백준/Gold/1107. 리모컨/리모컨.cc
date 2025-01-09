#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	unordered_map<int, int>mm;
	for (int i = 0; i < m; ++i)
	{
		int a = 0;
		cin >> a;
		mm[a]++;
	}
	int ans = abs(n - 100);
	for (int i = 0; i <= 999999; ++i)
	{
		string str = to_string(i);
		bool check = true;
		for (auto& k : str)
		{
			if (mm[k - '0'])
			{
				check = false;
				break;
			}
		}
		if (check)
		{
			int b = str.size() + abs(i - n);
			ans = min(ans, b);
		}
	}
	cout << ans;
	return 0;
}
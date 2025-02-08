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
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, m = 0, l = 0, k = 0;
	cin >> n >> m >> l >> k;
	vector<pii>v(k);
	for (auto& [i, j] : v)
	{
		cin >> i >> j;
	}
	int ans = k;
	for (int i = 0; i < k; ++i)
	{
		int x = v[i].first;
		for (int j = 0; j < k; ++j)
		{
			int y = v[j].second;
			int cnt = 0;
			for (int z = 0; z < k; ++z)
			{
				auto [nx, ny] = v[z];
				if (x <= nx && nx <= x + l && y <= ny && ny <= y + l)
				{
					cnt++;
				}
			}
			ans = min(ans, k - cnt);
		}
	}
	cout << ans;
	return 0;
}
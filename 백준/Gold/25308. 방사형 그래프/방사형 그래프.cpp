#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double>pdd;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<double>vc(8);
	for (auto& i : vc)
	{
		cin >> i;
	}
	vector<double>v;
	auto ccw = [&]
		{
			double sq = sqrt(2);
			vector<pdd>temp = { {0,v[0]},{v[1] / sq, v[1] / sq}, {v[2], 0},{v[3] / sq, -v[3] / sq}, {0,-v[4]},{-v[5] / sq, -v[5] / sq}, {-v[6],0},{-v[7] / sq, v[7] / sq} };
			for (int i = 0; i < 8; ++i)
			{
				
				double t = temp[i].first * temp[(i + 1) % 8].second + temp[(i + 1) % 8].first * temp[(i + 2) % 8].second + temp[(i + 2) % 8].first * temp[i].second;
				t -= temp[i].second * temp[(i + 1) % 8].first + temp[(i + 1) % 8].second * temp[(i + 2) % 8].first + temp[(i + 2) % 8].second * temp[i].first;
				if (t >= 0)
				{
					return false;
				}
			}
			return true;
		};
	int ans = 0;
	function<void(int)> dfs = [&](int mask)
		{
			if (mask == (1 << 8) - 1)
			{
				if (ccw())
				{
					ans++;
				}
				return;
			}
			for (int i = 0; i < 8; ++i)
			{
				if (!(mask & (1 << i)))
				{
					mask |= (1 << i);
					v.push_back(vc[i]);
					dfs(mask);
					v.pop_back();
					mask &= ~(1 << i);
				}
			}
		};
	dfs(0);
	cout << ans;
	return 0;
}
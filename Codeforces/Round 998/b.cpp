#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		ll n = 0, m = 0;
		cin >> n >> m;
		vector<vector<ll>>v(n, vector<ll>(m, 0));
		vector<vector<ll>>p(n, vector<ll>(m, 0));
		vector<ll>card;
		map<vector<ll>, vector<ll>>mm;
		for (auto& i : v)
		{
			for (auto& j : i)
			{
				cin >> j;
				card.push_back(j);
			}
		}
		sort(card.begin(), card.end());
		ll cnt = 1;
		for (auto& i : v)
		{
			if (i.empty())
			{
				continue;
			}
			sort(i.begin(), i.end());
			mm[i].push_back(cnt++);
		}
		for (ll i = 0; i < n; ++i)
		{
			for (ll j = 0; j < m; ++j)
			{
				p[i][j] = card[i + j * n];
			}
		}
		vector<ll>per(n, -1);
		bool flag = true;
		for (ll i = 0; i < n; ++i)
		{
			if (mm.find(p[i]) == mm.end())
			{
				flag = false;
				break;
			}
			per[i] = mm[p[i]].back();
			mm[p[i]].pop_back();
		}
		if (!flag)
		{
			cout << -1 << '\n';
		}
		else
		{
			for (auto& i : per)
			{
				cout << i << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}

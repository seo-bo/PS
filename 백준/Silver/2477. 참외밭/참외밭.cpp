#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll k = 0;
	cin >> k;
	int w = 0, h = 0;
	vector<pii>v;
	for (int i = 0; i < 6; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		if (a == 1 || a == 2)
		{
			w = max(w, b);
		}
		else if (a == 3 || a == 4)
		{
			h = max(h, b);
		}
		v.push_back(make_pair(a, b));
	}
	ll ans = w * h;
	for (int i = 0; i < 6; ++i)
	{
		if (v[i].first == v[(i + 2) % 6].first && v[(i + 1) % 6].first == v[(i + 3) % 6].first)
		{
			ans -= v[(i + 1) % 6].second * v[(i + 2) % 6].second;
			break;
		}
	}
	cout << ans * k;
	return 0;
}
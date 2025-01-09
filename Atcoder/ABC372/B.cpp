#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
typedef tuple<ll, ll, ll>tl;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int m = 0;
	cin >> m;
	vector<ll>v(11, 0);
	v[0] = 1;
	for (int i = 1; i <= 10; ++i)
	{
		v[i] = v[i - 1] * 3;
	}
	vector<ll>ans;
	while (m > 0)
	{
		ll temp = 0;
		for (int i = 10; i >= 0; --i)
		{
			if (v[i] <= m)
			{
				temp = i;
				break;
			}
		}
		ans.push_back(temp);
		m -= v[temp];
	}
	cout << ans.size() << '\n';
	for (auto& i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}

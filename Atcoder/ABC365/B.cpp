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
	int T = 1;
	while (T--)
	{
		int n = 0;
		cin >> n;
		vector<pii>v(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> v[i].first;
			v[i].second = i + 1;
		}
		sort(v.begin(), v.end(), [&](pii& a, pii& b)
			{
				if (a.first == b.first)
				{
					return a.second < b.second;
				}
				return a.first > b.first;
			});
		cout << v[1].second;
	}
	return 0;
}

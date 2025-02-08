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
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	sort(v.begin(), v.end());
	int g = v[1] - v[0];
	for (int i = 2; i < n; ++i)
	{
		g = gcd(g, v[i] - v[i - 1]);
	}
	vector<int>ans;
	for (int i = 2; i * i <= g; ++i)
	{
		if (!(g % i))
		{
			ans.push_back(i);
			if (i != g / i)
			{
				ans.push_back(g / i);
			}
		}
	}
	ans.push_back(g);
	sort(ans.begin(), ans.end());
	for (auto& i : ans)
	{
		if (i > 1)
		{
			cout << i << ' ';
		}
	}
	return 0;
}
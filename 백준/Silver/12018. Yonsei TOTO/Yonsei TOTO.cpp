#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, m = 0, ans = 0;
	cin >> n >> m;
	vector<int>v;
	for (int i = 0; i < n; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		vector<int>temp(a);
		for (auto& j : temp)
		{
			cin >> j;
		}
		if (a < b)
		{
			v.push_back(1);
		}
		else
		{
			sort(temp.begin(), temp.end(), greater<int>());
			v.push_back(temp[b - 1]);
		}
	}
	sort(v.begin(), v.end());
	for (auto& i : v)
	{
		if (m >= i)
		{
			m -= i;
			ans++;
		}
		else
		{
			break;
		}
	}
	cout << ans;
	return 0;
}
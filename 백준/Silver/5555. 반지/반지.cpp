#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str;
	int n = 0, ans = 0;
	cin >> str >> n;
	vector<string>v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
		v[i] += v[i];
		if (v[i].find(str) != string::npos)
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
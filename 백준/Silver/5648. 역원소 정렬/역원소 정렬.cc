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
	int n = 0;
	cin >> n;
	vector<ll>v(n);
	for (auto& i : v)
	{
		string str;
		cin >> str;
		reverse(str.begin(), str.end());
		i = stoll(str);
	}
	sort(v.begin(), v.end());
	for (auto& i : v)
	{
		cout << i << '\n';
	}
	return 0;
}
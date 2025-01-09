#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	ll T = 0, cnt = 0;
	vector<int>v = { 1,1,3 };
	for (int i = 0; i < n; ++i)
	{
		ll temp = 0;
		cin >> temp;
		T += (temp / 5) * 3;
		temp %= 5;
		while (temp > 0)
		{
			temp -= v[cnt];
			T++;
			cnt = (cnt + 1) % 3;
		}
	}
	cout << T;
	return 0;
}

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
	int n = 0, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string a;
		cin >> a;
		string b = a;
		reverse(a.begin(), a.end());
		if (a == b)
		{
			cnt++;
		}
	}
	cout << max(0, cnt * (cnt - 1));
	return 0;
}
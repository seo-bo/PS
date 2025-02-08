#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void) // n의 반쪽? -> n^2의 n개 보좌 가능.
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<ll>v;
	ll ans = 0, ok = 0;
	for (int i = 0; i < n; ++i)
	{
		ll temp = 0;
		cin >> temp;
		if (temp == 1)
		{
			ans++;
		}
		else
		{
			v.push_back(temp);
		}
	}
	sort(v.begin(), v.end());
	ll pre = 0;
	for (auto& i : v)
	{
		ll p = log2(i);
		if (log2(i) != pre)
		{
			ok <<= (p - pre);
			pre = p;
		}
		if (!ok)
		{
			ok = i - 1;
			ans++;
		}
		else
		{
			ok--;
		}
	}
	cout << ans;
	return 0;
}
#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<lb, lb> plb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n = 0, c = 0, ans = 1;
	cin >> n >> c;
	vector<int>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	int pivot = v[0];
	for (int i = 1; i < n; ++i)
	{
		if (v[i] - pivot >= c)
		{
			ans++;
			pivot = v[i];
		}
	}
	cout << ans;
	return 0;
}

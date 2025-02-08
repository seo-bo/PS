#include <bits/stdc++.h>
#include <unordered_set>
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
	ll n = 0;
	cin >> n;
	vector<ll>ans(n, 0);
	ll idx = 0, pivot = 1, dest = n / 2;
	if (n % 2) // 홀수일때
	{
		idx = n - 2;
	}
	else
	{
		idx = n - 1;
	}
	for (int i = 0; i < dest - 1; ++i)
	{
		ans[idx] = pivot++;
		idx -= 2;
	}
	ans[0] = pivot++;
	for (int i = 0; i < n; ++i)
	{
		if (!ans[i])
		{
			ans[i] = pivot++;
		}
	}
	for (auto& i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}
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
	ll n = 0, k = 0;
	cin >> n >> k;
	vector<ll>v(n);
	vector<ll>ok, ban;
	for (auto& i : v)
	{
		cin >> i;
		if (i >= k)
		{
			ok.push_back(i);
		}
		else
		{
			ban.push_back(i);
		}
	}
	sort(ban.begin(), ban.end());
	ll left = 0, right = ban.size() - 1;
	vector<ll>p;
	while (left < right)
	{
		if (ban[left] + ban[right] >= k)
		{
			p.push_back(ban[left] + ban[right]);
			left++;
			right--;
		}
		else
		{
			left++;
		}
	}
	for (auto& i : p)
	{
		ok.push_back(i);
	}
	sort(ok.begin(), ok.end());
	if (ok.empty() || ok[0] < k)
	{
		cout << -1;
		return 0;
	}
	ll ans = 1;
	ll pre = ok[0];
	for (int i = 1; i < ok.size(); ++i)
	{
		if (ok[i] >= pre)
		{
			ans++;
			pre = ok[i];
		}
	}
	cout << ans;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, k = 0, ct = 0;
	cin >> n >> k;
	vector<ll>v(k), pre1(1, 0), tt(k), pre2(1, 0);
	for (auto& i : v)
	{
		cin >> i;
		pre1.push_back(pre1.back() + i);
	}
	for (ll i = 0; i < k; ++i)
	{
		tt[i] = 1LL * v[i] - i;
		pre2.push_back(pre2.back() + tt[i]);
	}
	vector<ll>temp = tt;
	sort(temp.begin(), temp.end());
	temp.erase(unique(temp.begin(), temp.end()), temp.end());
	ll len = temp.size() + 2;
	vector<ll>sum(len * 4, 0), cnt(len * 4, 0);
	function<void(ll, ll, ll, ll, ll, ll)> update = [&](ll start, ll end, ll node, ll pos, ll cntv, ll sumv)
		{
			if (pos < start || pos > end)
			{
				return;
			}
			if (start == end)
			{
				cnt[node] += cntv;
				sum[node] += sumv;
				return;
			}
			ll mid = (start + end) / 2;
			if (pos <= mid)
			{
				update(start, mid, node * 2, pos, cntv, sumv);
			}
			else
			{
				update(mid + 1, end, node * 2 + 1, pos, cntv, sumv);
			}
			cnt[node] = cnt[node * 2] + cnt[node * 2 + 1];
			sum[node] = sum[node * 2] + sum[node * 2 + 1];
		};
	function<pll(ll, ll, ll, ll, ll)> query = [&](ll start, ll end, ll node, ll left, ll right)
		{
			if (start > right || left > end)
			{
				return make_pair(0LL, 0LL);
			}
			if (left <= start && end <= right)
			{
				return make_pair(cnt[node], sum[node]);
			}
			ll mid = (start + end) / 2;
			auto ll = query(start, mid, node * 2, left, right);
			auto rr = query(mid + 1, end, node * 2 + 1, left, right);
			return make_pair(ll.first + rr.first, ll.second + rr.second);
		};
	ll start = 3, end = k - n - 1;
	for (ll i = start; i < start + n - 2; ++i)
	{
		auto it = lower_bound(temp.begin(), temp.end(), tt[i]) - temp.begin() + 1;
		update(1, len, 1, it, 1, tt[i]);
	}
	ll ans = LLONG_MAX;
	for (ll i = start; i <= end; ++i)
	{
		ll idx = i - 3;
		ll s1 = pre1[idx + 3] - pre1[idx], c1 = s1 - 3;
		ll s2 = pre1[idx + n + 4] - pre1[idx + n + 1], c2 = n * 3 - s2;
		ll sub = pre2[i + n - 2] - pre2[i], siz = n - 2;
		ll val = -(idx + 1) - 1, ncnt = 0, nsum = 0;
		ll bdx = upper_bound(temp.begin(), temp.end(), val) - temp.begin();
		if (bdx > 0)
		{
			auto [a, b] = query(1, len, 1, 1, bdx);
			ncnt = a, nsum = b;
		}
		ll rb = sub - nsum * 2 + (idx + 1) * (siz - ncnt * 2);
		ll tot = c1 + c2 + rb;
		ans = min(ans, tot);
		if (!ans)
		{
			break;
		}
		if (i < end)
		{
			auto it = lower_bound(temp.begin(), temp.end(), tt[i]) - temp.begin() + 1;
			update(1, len, 1, it, -1, -tt[i]);
			ll right = i + n - 2;
			auto jt = lower_bound(temp.begin(), temp.end(), tt[right]) - temp.begin() + 1;
			update(1, len, 1, jt, 1, tt[right]);
		}
	}
	cout << ans;
	return 0;
}
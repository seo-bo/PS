#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll, ll, ll> tp;
typedef tuple<ll, ll, ll, ll> tl;
struct cmp
{
	bool operator()(const tp& a, const tp& b) const
	{
		if (get<0>(a) == get<0>(b))
		{
			if (get<1>(a) == get<1>(b))
			{
				return get<2>(a) < get<2>(b);
			}
			return get<1>(a) < get<1>(b);
		}
		return get<0>(a) < get<0>(b);
	}
};

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, k = 0;
	cin >> n >> k;
	vector<ll>a(n), b(n), c(n);
	for (auto& i : a)
	{
		cin >> i;
	}
	for (auto& i : b)
	{
		cin >> i;
	}
	for (auto& i : c)
	{
		cin >> i;
	}
	sort(a.rbegin(), a.rend());
	sort(b.rbegin(), b.rend());
	sort(c.rbegin(), c.rend());
	priority_queue<tl>pq;
	set<tp, cmp>visited;
	auto sv = [&](tp ok)
		{
			auto& [idx, jdx, kdx] = ok;
			return a[idx] * b[jdx] + b[jdx] * c[kdx] + c[kdx] * a[idx];
		};
	tp _ = make_tuple(0, 0, 0);
	pq.push(make_tuple(sv(_), 0, 0, 0));
	visited.insert(_);
	for (ll i = 1; i < k; ++i)
	{
		auto [cost, idx, jdx, kdx] = pq.top();
		pq.pop();
		if (idx + 1 < n)
		{
			tp nxt = make_tuple(idx + 1, jdx, kdx);
			if (visited.find(nxt) == visited.end())
			{
				visited.insert(nxt);
				pq.push(make_tuple(sv(nxt), idx + 1, jdx, kdx));
			}

		}
		if (jdx + 1 < n)
		{
			tp nxt = make_tuple(idx, jdx + 1, kdx);
			if (visited.find(nxt) == visited.end())
			{
				visited.insert(nxt);
				pq.push(make_tuple(sv(nxt), idx, jdx + 1, kdx));
			}
		}
		if (kdx + 1 < n)
		{
			tp nxt = make_tuple(idx, jdx, kdx + 1);
			if (visited.find(nxt) == visited.end())
			{
				visited.insert(nxt);
				pq.push(make_tuple(sv(nxt), idx, jdx, kdx + 1));
			}
		}
	}
	cout << get<0>(pq.top());
	return 0;
}

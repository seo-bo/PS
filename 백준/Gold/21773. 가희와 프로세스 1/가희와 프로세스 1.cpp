#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll, ll, ll> tp;

struct cmp
{
	bool operator() (const tp& a, const tp& b)
	{
		if (get<2>(a) == get<2>(b))
		{
			return get<0>(a) > get<0>(b);
		}
		return get<2>(a) < get<2>(b);
	};
};

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, t = 0;
	cin >> t >> n;
	priority_queue<tp, vector<tp>, cmp>pq;
	for (int i = 0; i < n; ++i)
	{
		ll a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		pq.push(make_tuple(a, b, c));
	}
	for (int i = 1; i <= t; ++i)
	{
		tp temp = pq.top();
		pq.pop();
		cout << get<0>(temp) << '\n';
		get<1>(temp)--;
		get<2>(temp)--;
		if (get<1>(temp) != 0)
		{
			pq.push(temp);
		}
	}
	return 0;
}
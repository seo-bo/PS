#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct ag
{
	ll t, b, idx;
};

struct cmp
{
	bool operator() (const ag& a, const ag& b) const
	{
		if (a.t == b.t)
		{
			if (a.b == b.b)
			{
				return a.idx > b.idx;
			}
			return a.b > b.b;
		}
		return a.t < b.t;
	}
};


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	ll time = 0;
	cin >> n;
	priority_queue<ag, vector<ag>, cmp> pq;
	vector<tuple<int, int, int, int>>v(n);
	for (int i = 0; i < n; ++i)
	{
		auto& [a, b, c, d] = v[i];
		cin >> a >> b >> c;
		d = i + 1;
	}
	for (auto& [a, b, c, d] : v)
	{
		while (!pq.empty() && time < a)
		{
			cout << pq.top().idx << ' ';
			time += pq.top().b;
			pq.pop();
		}
		if (a <= time)
		{
			pq.push({ b - a, c, d });
		}
		else
		{
			time = a;
			pq.push({ b - a, c, d });
		}
	}
	while (!pq.empty())
	{
		cout << pq.top().idx << ' ';
		pq.pop();
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

struct t
{
	int a, b, c, d, r;
};

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0, k = 0;
	cin >> n >> k;
	vector<t>v(n);
	for (auto& i : v)
	{
		cin >> i.a >> i.b >> i.c >> i.d;
	}
	sort(v.begin(), v.end(), [&](const t& a, const t& b)
		{
			if (a.b == b.b)
			{
				if (a.c == b.c)
				{
					return a.d > b.d;
				}
				return a.c > b.c;
			}
			return a.b > b.b;
		});
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans++;
		if (i > 0 && (v[i].b != v[i - 1].b || v[i].c != v[i - 1].c || v[i].d != v[i - 1].d))
		{
			v[i].r = ans;
		}
		else if (!i)
		{
			v[i].r = ans;
		}
		else
		{
			v[i].r = v[i - 1].r;
		}
		if (v[i].a == k)
		{
			cout << v[i].r;
			return 0;
		}
	}
	return 0;
}
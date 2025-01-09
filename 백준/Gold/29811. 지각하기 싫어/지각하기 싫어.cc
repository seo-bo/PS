#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0, temp = 0;
	cin >> n >> m;
	set<pii>P1;
	set<pii>P2;
	vector<int>v(n + m + 2);
	for (int i = 1; i <= n + m; ++i)
	{
		cin >> temp;
		if (i <= n)
		{
			P1.insert({ temp,i });
		}
		else
		{
			P2.insert({ temp,i });
		}
		v[i] = temp;
	}
	int query = 0;
	cin >> query;
	for (int i = 0; i < query; ++i)
	{
		char c;
		cin >> c;
		switch (c)
		{
		case 'U':
		{
			int idx = 0, value = 0;
			cin >> idx >> value;
			if (idx <= n)
			{
				P1.erase(make_pair(v[idx], idx));
				P1.insert(make_pair(value, idx));
			}
			else
			{
				P2.erase(make_pair(v[idx], idx));
				P2.insert(make_pair(value, idx));
			}
			v[idx] = value;
			break;
		}
		case 'L':
		{
			cout << (*P1.begin()).second << " " << (*P2.begin()).second << "\n";
			break;
		}
		}
	}
	return 0;
}
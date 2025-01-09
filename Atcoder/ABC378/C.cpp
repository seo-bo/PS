#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	map<ll, ll>mm;
	for (int i = 1; i <= n; ++i)
	{
		ll temp = 0;
		cin >> temp;
		if (mm.find(temp) == mm.end())
		{
			cout << -1 << ' ';
		}
		else
		{
			cout << mm[temp] << ' ';
		}
		mm[temp] = i;
	}
	return 0;
}

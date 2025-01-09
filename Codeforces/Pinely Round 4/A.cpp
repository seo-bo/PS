#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		vector<ll>v(n);
		for(auto & i : v)
		{
			cin >> i;
		}
		ll pivot = 0;
		for(int i =0; i<n; i+=2)
		{
	        pivot = max(pivot,v[i]);
		}
		cout << pivot << '\n';
	}
	return 0;
}

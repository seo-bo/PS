#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	unordered_map<string, int>m;
	ll n = 0;
	cin >> n;
	(n & 1) ? (cout << "SK") : (cout << "CY");
	return 0;
}
#include <bits/stdc++.h>
#include <unordered_set>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	ll p = 0, c = 0, k = 0;
	cin >> p >> c >> k;
	vector<ll>D(p + 1, 0);
	vector<ll>nD(k + 1, 0);
	vector<ll>v(p, 0);
	/*
	d5 = -(c * d4 + c^2 * d3 + c^3 * d2)
	d4 = -(c * d3 + c^2 * d2 + c^3 * d1)
	대입하면, d5 = c^4 * d1?
	d6 = -(c * d5 + c^2 * d4 + c^3 * d3)
	대입하면, d6 = c^5 * d2
	주기성........................??
	*/
	for (auto& i : v)
	{
		cin >> i;
	}
	for (int i = 1; i < p; ++i)
	{
		D[i] = v[i] - v[i - 1];
	}
	ll cc = c;
	for (int i = 1; i <= p - 1; ++i)
	{
		D[p] -= cc * D[p - i];
		cc *= c;
	}
	D[p] = llabs(D[p]) % MOD; // 쩌피 오버플로우 안나잖아
	for (int i = 1; i <= p; ++i)
	{
		nD[i] = llabs(D[i]);
	}
	ull nc = cc;
	for (int i = p + 1; i <= k; ++i)
	{
		nD[i] = (nc * nD[i - p]) % MOD;
	}
	cout << nD[k];
	return 0;
}
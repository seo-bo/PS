#include <bits/stdc++.h>
#include <unordered_set>
#define MOD 1000000007;
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<lb, lb> plb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<ll>power(100010, 1);
	for (int i = 1; i <= 100000; ++i)
	{
		power[i] = (power[i - 1] * 2) % MOD;
	}
	int T = 0;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		ll temp = 0;
		cin >> temp;
	}
	for (int i = 0; i < T; ++i)
	{
		ll temp = 0;
		cin >> temp;
		cout << power[temp] << '\n';
	}
	return 0;
}

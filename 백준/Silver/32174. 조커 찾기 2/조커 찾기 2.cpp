#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int>ti;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	ll n = 0, m = 0, joker = 0;
	cin >> n >> m;
	vector<ll>card(100002, -1);
	card[0] = 0;
	for (int i = 1; i <= m; ++i)
	{
		ll a = 0, b = 0;
		cin >> a >> b;
		if (a == 1)
		{
			joker = (joker + (b % n)) % n;
		}
		else if (a == 2)
		{
			joker = (joker - (b % n) + n) % n;
		}
		else
		{
			joker = card[b];
		}
		card[i] = joker;
	}
	cout << joker + 1;
	return 0;
}
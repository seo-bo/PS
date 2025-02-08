#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const char* yes = "Yes";
const char* no = "No";

int main(void)
{
	cin.tie(0)->ios::sync_with_stdio(0);
	vector<bool>f(1000050, false);
	vector<ll>prime;
	for (ll i = 2; i <= 1000000; ++i)
	{
		if (!f[i])
		{
			prime.push_back(i);
			for (ll j = i * i; j <= 1000000; j += i)
			{
				f[j] = true;
			}
		}
	}
	int T = 0;
	cin >> T;
	while (T--)
	{
		ll a = 0;
		cin >> a;
		bool check = true;
		for (auto& i : prime)
		{
			if (!(a % i))
			{
				check = false;
				break;
			}
		}
		if (check)
		{
			cout << "YES" << '\n';
		}
		else
		{
			cout << "NO" << '\n';
		}
	}
	return 0;
}
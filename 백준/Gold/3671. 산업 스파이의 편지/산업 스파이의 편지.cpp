#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<bool>prime(10000005, true);
	prime[0] = prime[1] = false;
	for (ll i = 2; i * i <= 10000000; ++i)
	{
		if (prime[i])
		{
			for (ll j = i * i; j <= 10000000; j += i)
			{
				prime[j] = false;
			}
		}
	}
	int T = 0;
	cin >> T;
	while (T--)
	{
		string str;
		cin >> str;
		vector<int>v;
		for (auto& i : str)
		{
			v.push_back(i - '0');
		}
		sort(v.begin(), v.end());
		unordered_set<int>ss;
		do
		{
			vector<ll>base(v.size() + 1, 0);
			for (int i = 1; i <= v.size(); ++i)
			{
				base[i] = base[i - 1] * 10 + v[i - 1];
			}
			for (int i = 1; i <= v.size(); ++i)
			{
				if (prime[base[i]])
				{
					ss.insert(base[i]);
				}
			}
		} while (next_permutation(v.begin(), v.end()));
		cout << ss.size() << '\n';
	}
	return 0;
}

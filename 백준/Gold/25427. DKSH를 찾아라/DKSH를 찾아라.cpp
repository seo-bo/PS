#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	string str;
	cin >> str;
	vector<ll>H, S, K, D;
	for (ll i = 0; i < n; ++i)
	{
		if (str[i] == 'H')
		{
			H.push_back(i);
		}
		else if (str[i] == 'S')
		{
			S.push_back(i);
		}
		else if (str[i] == 'K')
		{
			K.push_back(i);
		}
		else if (str[i] == 'D')
		{
			D.push_back(i);
		}
	}
	vector<ll>sum((ll)H.size(), 0);
	iota(sum.begin(), sum.end(), 1);
	auto cal = [&](vector<ll>& base, vector<ll>& target)
		{
			vector<ll>prefix;
			if (target.empty() || base.empty())
			{
				cout << 0;
				exit(0);
			}
			ll len = target.size() - 1;
			for (auto& i : base)
			{
				ll idx = upper_bound(target.begin(), target.end(), i) - target.begin();
				ll pivot = sum[len];
				if (idx)
				{
					pivot -= sum[idx - 1];
				}
				if (prefix.empty())
				{
					prefix.push_back(pivot);
				}
				else
				{
					prefix.push_back(prefix.back() + pivot);
				}
			}
			return prefix;
		};
	sum = cal(S, H);
	sum = cal(K, S);
	sum = cal(D, K);
	cout << sum.back();
	return 0;
}
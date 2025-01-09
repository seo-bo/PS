#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, idx = 1;
	cin >> n;
	cin.ignore();
	string str, temp;
	getline(cin, str);
	stringstream ss(str);
	vector<string>v;
	while (ss >> temp)
	{
		v.push_back(temp);
	}
	vector<ll>prefix(n + 1, 0);
	vector<int>flag(n + 1, 0);
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i] == "S" || v[i] == "DS")
		{
			if (i + 2 < v.size() && v[i + 1] == "or" && (v[i + 2] == "S" || v[i + 2] == "DS"))
			{
				flag[idx++] = 3;
				i += 2;
			}
			else
			{
				flag[idx++] = (v[i] == "S") ? 1 : 2;
			}
		}
		else
		{
			prefix[idx++] = stoll(v[i]);
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		prefix[i] = prefix[i - 1] + prefix[i];
	}
	ll ans = prefix[n], sum = LLONG_MAX;
	for (int i = 1; i <= n; ++i)
	{
		if (flag[i] & 2)
		{
			ans = max(ans, prefix[n] + prefix[i]);
		}
		if (flag[i] & 1)
		{
			sum = min(sum, prefix[i - 1]);
		}
		if (flag[i] & 2)
		{
			if (sum != LLONG_MAX)
			{
				ans = max(ans, prefix[n] + prefix[i] - sum);
			}
		}
	}
	cout << ans;
	return 0;
}
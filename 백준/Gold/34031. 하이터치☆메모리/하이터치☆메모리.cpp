#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string A, B;
	cin >> A >> B;
	int alen = A.length(), blen = B.length();
	vector<int>prefix(alen + 1);
	for (int i = 1; i <= alen; ++i)
	{
		prefix[i] = prefix[i - 1] + ((A[i - 1] == '(') ? 1 : -1);
	}
	map<int, vector<int>>v;
	int cur = 0;
	for (int i = 1; i <= blen; ++i)
	{
		cur = cur + ((B[i - 1] == '(') ? 1 : -1);
		v[-cur].push_back(i);
	}
	ll ans = 0;
	for (int i = 1; i <= alen; ++i)
	{
		if (prefix[i] == -1)
		{
			break;
		}
		auto it = v.upper_bound(prefix[i]);
		if (it == v.end())
		{
			ans += v[prefix[i]].size();
			continue;
		}
		int fst = INT_MAX;
		if (!it->second.empty())
		{
			fst = *it->second.begin();
		}
		auto jt = v[prefix[i]];
		ans += lower_bound(jt.begin(), jt.end(), fst) - jt.begin();
	}
	cout << ans;
	return 0;
}
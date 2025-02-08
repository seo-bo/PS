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
	int n = 0, plus = 0, mul = 0;
	cin >> n;
	vector<int>v(n);
	ll ans = 0;
	for (auto& i : v)
	{
		cin >> i;
	}
	cin >> plus >> mul;
	if (!mul)
	{
		for (auto& i : v)
		{
			ans += i;
		}
		cout << ans;
		return 0;
	}
	sort(v.begin(), v.end());
	auto cal = [&](vector<int>t, vector<int>prefix) // t가 의미하는것. 경계 나누기
		{
			ll temp = 0;
			int idx = 0, siz = t.size();
			for (int i = 0; i < siz; ++i)
			{
				if (i == 0)
				{
					temp = prefix[t[i]] - prefix[idx];
					idx = t[i];
				}
				if (i == siz - 1)
				{
					temp *= prefix[n] - prefix[idx];
				}
				else
				{
					temp *= prefix[t[i + 1]] - prefix[idx];
					idx = t[i + 1];
				}
			}
			ans = max(ans, temp);
		};
	function<void(int, int, vector<int>, vector<int>)> dfs = [&](int depth, int st, vector<int>t, vector<int>prefix)
		{
			if (depth == mul)
			{
				cal(t, prefix);
			}
			for (int i = st; i <= n - 1; ++i)
			{
				t.push_back(i);
				dfs(depth + 1, i + 1, t, prefix);
				t.pop_back();
			}
		};
	do
	{
		vector<int>prefix(n + 1, 0);
		for (int i = 1; i <= n; ++i)
		{
			prefix[i] = prefix[i - 1] + v[i - 1];
		}
		dfs(0, 1, vector<int>(), prefix);
	} while (next_permutation(v.begin(), v.end()));
	cout << ans;
	return 0;
}
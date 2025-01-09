#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	ll len = str.size();
	set<ll>s;
	vector<ll>ans;
	function<void(ll)> dfs = [&](ll idx)
		{
			if (idx == len)
			{
				if (*(prev(s.end())) == s.size())
				{
					for (auto& i : ans)
					{
						cout << i << ' ';
					}
					exit(0);
				}
			}
			ll a = str[idx] - '0';
			if (1 <= a && a <= 50 && s.find(a) == s.end())
			{
				s.insert(a);
				ans.push_back(a);
				dfs(idx + 1);
				ans.pop_back();
				s.erase(a);
			}
			if (idx + 1 < len)
			{
				ll b = (str[idx] - '0') * 10 + (str[idx + 1] - '0');
				if (1 <= b && b <= 50 && s.find(b) == s.end())
				{
					s.insert(b);
					ans.push_back(b);
					dfs(idx + 2);
					ans.pop_back();
					s.erase(b);
				}
			}
		};
	dfs(0);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	string str;
	ll ans = -LLONG_MAX;
	cin >> n >> str;
	vector<string> v(n);
	for (int i = 0; i < n; ++i)
	{
		v[i] = str[i];
	}
	auto cal = [&](vector<string> R)
		{
			ll sum = 0;
			vector<string> post;
			vector<string> temp;
			for (auto& i : R)
			{
				if (i == "+" || i == "-")
				{
					while (!temp.empty())
					{
						post.push_back(temp.back());
						temp.pop_back();
					}
					temp.push_back(i);
				}
				else if (i == "*")
				{
					while (!temp.empty() && temp.back() == "*")
					{
						post.push_back(temp.back());
						temp.pop_back();
					}
					temp.push_back(i);
				}
				else
				{
					post.push_back(i);
				}
			}
			while (!temp.empty())
			{
				post.push_back(temp.back());
				temp.pop_back();
			}
			vector<ll> s;
			for (auto& i : post)
			{
				if (i == "+" || i == "-" || i == "*")
				{
					if (s.size() < 2)
					{
						continue;
					}
					ll b = s.back(); s.pop_back();
					ll a = s.back(); s.pop_back();
					if (i == "+")
					{
						s.push_back(a + b);
					}
					else if (i == "-")
					{
						s.push_back(a - b);
					}
					else
					{
						s.push_back(a * b);
					}
				}
				else
				{
					s.push_back(stoll(i));
				}
			}
			if (!s.empty())
			{
				ans = max(ans, s.back());
			}
			return;
		};
	auto c = [&](string a, string b, string c)->string
		{
			ll A = stoll(a), C = stoll(c);
			if (b == "-")
			{
				return to_string(A - C);
			}
			else if (b == "+")
			{
				return to_string(A + C);
			}
			return to_string(A * C);
		};
	function<void(int, vector<string>)> dfs = [&](int depth, vector<string> now)->void
		{
			if (depth == n)
			{
				cal(now);
				return;
			}
			now.push_back(v[depth]);
			dfs(depth + 1, now);
			now.pop_back();
			if ("0" <= v[depth] && v[depth] <= "9" && depth < n - 2)
			{
				now.push_back(c(v[depth], v[depth + 1], v[depth + 2]));
				dfs(depth + 3, now);
				now.pop_back();
			}
		};
	dfs(0, vector<string>());
	cout << ans;
	return 0;
}
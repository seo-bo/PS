#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str;
	cin >> str;
	vector<string>s;
	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] == '(' && str[i + 1] == ')')
		{
			s.push_back("2");
			++i;
		}
		else if (str[i] == '[' && str[i + 1] == ']')
		{
			s.push_back("3");
			++i;
		}
		else if (str[i] == '(')
		{
			s.push_back("(");
		}
		else if (str[i] == '[')
		{
			s.push_back("[");
		}
		else if (str[i] == ')')
		{
			ll sum = 0;
			while (!s.empty() && s.back() != "(" && s.back() != "[")
			{
				sum += stoi(s.back());
				s.pop_back();
			}
			if (s.empty() || s.back() != "(")
			{
				cout << 0;
				return 0;
			}
			s.pop_back();
			s.push_back(to_string(sum * 2));
		}
		else
		{
			ll sum = 0;
			while (!s.empty() && s.back() != "(" && s.back() != "[")
			{
				sum += stoi(s.back());
				s.pop_back();
			}
			if (s.empty() || s.back() != "[")
			{
				cout << 0;
				return 0;
			}
			s.pop_back();
			s.push_back(to_string(sum * 3));
		}
	}
	ll ans = 0;
	while (!s.empty())
	{
		if (s.back() == "(" || s.back() == "[" || s.back() == ")" || s.back() == "]")
		{
			cout << 0;
			return 0;
		}
		ans += stoi(s.back());
		s.pop_back();
	}
	cout << ans;
	return 0;
}